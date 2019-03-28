#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
    int N = 100;
    int tri[N][N];
    for(int i=0;i<N;i++)
        for(int j=0;j<=i;j++)
            scanf("%d",&tri[i][j]);
    for(int i=N-2;i>=0;i--)
    {
        for(int j=0;j<=i;j++)
            tri[i][j] = tri[i][j] + max( tri[i+1][j], tri[i+1][j+1] );
    }
    printf("%d\n",tri[0][0]);
    return 0;
}
