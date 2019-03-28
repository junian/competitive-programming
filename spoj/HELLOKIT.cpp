#include<cstdio>
#include<cstring>

int main()
{
    char a[256];
    char b[999999];
    int n,i,l,j,m,x;
    while(1)
    {
        scanf("%s", a);
        if(strcmp(a,".")==0)
            break;
        scanf("%d", &n);
        strcpy(b,a);
        for(i=1;i<n;i++)
            strcat(b,a);
        m=strlen(a);
        l=n*m;
        for(i=0;i<m;i++)
        {
            x=i;
            for(j=0;j<l;j++)
            {
                printf("%c", b[x]);
                x = (x+1)%m;
            }
            printf("\n");
        }
    }
    return 0;
}
