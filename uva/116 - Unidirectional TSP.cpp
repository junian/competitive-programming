#include <cstdio>
#include <algorithm>

#define p(i) i<1?m:i>m?1:i

using namespace std;

int m,n;
int c[11][101];
int r[10][101];

int main()
{
    int i,j,s,min;
    while(scanf("%d%d",&m,&n)!=EOF)
    {
        for(i=1;i<=m;i++)
            for(j=1;j<=n;j++)
                scanf("%d",&c[i][j]);
        for(j=n-1;j>=1;j--)
        {
            for(i=1;i<=m;i++)
            {
                if(c[p(i-1)][j+1] <= c[i][j+1] &&
                   c[p(i-1)][j+1] <= c[p(i+1)][j+1])
                {
                    r[i][[j]=p(i-1);
                    c[i][j] += c[p(i-1)][j+1];
                }
            }
        }
    }
    return 0;
}
