#include <cstdio>
#include <cstring>
#include <cstdlib>

int compare(const void*a, const void*b)
{
    char **x = (char**)a;
    char **y = (char**)b;
    char m[256];
    char n[256];
    strcpy(m,*x);
    strcat(m,*y);
    strcpy(n,*y);
    strcat(n,*x);
    return strcmp(n,m);
}

int main()
{
    int n,i;
    char **x=(char**)malloc(sizeof(char*)*50);
    for(i=0;i<50;i++)
        x[i] = (char*)malloc(sizeof(char)*256);
    while(1)
    {
        scanf("%d",&n);
        if(n==0)
            break;
        for(i=0;i<n;i++)
            scanf("%s",x[i]);
        qsort(x,n,sizeof(char*),compare);
        for(i=0;i<n;i++)
            printf("%s",x[i]);
        printf("\n");
    }
    return 0;
}
