#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
    int x[3];
    int t,i;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%d%d%d",&x[0],&x[1],&x[2]);
        sort(x,x+3);
        printf("Case %d: %d\n",i,x[1]);
    }
    return 0;
}
