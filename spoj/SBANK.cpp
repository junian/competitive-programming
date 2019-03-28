#include <cstdio>
#include <cstdlib>
#include <cstring>

int compare(const void*a, const void*b)
{
    char **x = (char**)a;
    char **y = (char**)b;
    return (strcmp(*x,*y));
}

int main()
{
    char **x=(char**)malloc(sizeof(char*)*100000);
    char k[18];
    int t,n,i,y,j;
    for(i=0;i<100000;i++)
        x[i] = (char*)malloc(sizeof(char)*31);
    scanf("%d",&t);
    while(t-->0)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%s",k);
            strcpy(x[i],k);
            strcat(x[i]," ");
            for(j=1;j<6;j++)
            {
                scanf("%s",k);
                strcat(x[i],k);
                strcat(x[i]," ");
            }
        }
        qsort(x, n, sizeof(char*), compare);
        y=1;
        if(n>0)
            printf("%s",x[0]);
        for(i=1;i<n;i++)
        {
            if(strcmp(x[i],x[i-1])!=0)
            {
                printf("%d\n%s",y,x[i]);
                y=1;
            }
            else
                y++;
        }
        printf("%d\n",y);
        if(t>0)
        {
            printf("\n");
        }
    }
    return 0;
}
