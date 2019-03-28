#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
    int a,b,i,j;
    int m[101][101];
    int mi;
    while(scanf("%d%d",&a,&b)!=EOF)
    {
        for(i=0;i<a;i++)
            for(j=0;j<b;j++)
                scanf("%d",&m[i][j]);
        for(i=a-2;i>=0;i--)
        {
            for(j=0;j<b;j++)
            {
                mi = m[i+1][j];
                if(j+1 < b)
                    mi = min(mi,m[i+1][j+1]);
                if(j-1 >= 0)
                    mi = min(mi,m[i+1][j-1]);
                m[i][j] += mi;
            }
        }
        mi=m[0][0];
        for(i=1;i<b;i++)
            if(m[0][i]<mi)
                mi=m[0][i];
        printf("%d\n",mi);
    }
    return 0;
}
