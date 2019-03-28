#include <cstdio>
int main()
{
    int a,b,t,i,j,k;
    scanf("%d",&t);
    while(t-->0)
    {
        scanf("%d%d",&a,&b);
        for(i=0;i<b;i++)
        {
            for(j=1;j<=a;j++)
            {
                for(k=0;k<j;k++)
                    printf("%d",j);
                printf("\n");
            }
            for(j=a-1;j>=1;j--)
            {
                for(k=0;k<j;k++)
                    printf("%d",j);
                printf("\n");
            }
            if(!(t==0 && i==b-1))
                printf("\n");
        }
    }
    return 0;
}
