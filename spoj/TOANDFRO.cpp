#include <cstdio>
#include <cstring>
int main()
{
    char z[201];
    char *x;
    char y[100][20];
    int i,j,c,l,r;
    while(1)
    {
        scanf("%d",&c);
        if(c==0) break;
        scanf("%s",z);
        l=strlen(z);
        r=l/c;
        x = z;
        for(i=0;i<r;i++)
        {
            if(i%2==0)
                for(j=0;j<c;j++)
                {
                    y[i][j]=*x;
                    x++;
                }
            else
                for(j=c-1;j>=0;j--)
                {
                    y[i][j]=*x;
                    x++;
                }
        }
        for(j=0;j<c;j++)
            for(i=0;i<r;i++)
                printf("%c",y[i][j]);
        printf("\n");
    }
    return 0;
}
