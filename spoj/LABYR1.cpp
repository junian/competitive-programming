#include <cstdio>

int s[1000][1000];
int c,r;

int main()
{
    int t,i,j;
    char x;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&c,&r);
        for(i=0;i<r;i++)
            for(j=0;j<c;j++)
            {
                x=getchar();
                s[i][j] = x=='#'?1:0;
            }
    }
    return 0;
}
