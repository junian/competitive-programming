#include <cstdio>
#include <algorithm>
using namespace std;
#define MAX 100000
long long r[MAX][3];
int main()
{
    int n,i,j,t=0;
    while(1)
    {
        scanf("%d",&n);
        if(n<2)
            break;
        for(i=0;i<n;i++)
            scanf("%lld%lld%lld",&r[i][0],&r[i][1],&r[i][2]);
        t++;
        r[0][2] += r[0][1];
        r[1][0] += r[0][1];
        r[1][1] += min(r[1][0],min(r[0][1],r[0][2]));
        r[1][2] += min(r[1][1],min(r[0][1],r[0][2]));
        for(i=2;i<n;i++)
        {
            r[i][0] += min(r[i-1][1],r[i-1][0]);
            r[i][1] += min(min(r[i][0],r[i-1][0]),min(r[i-1][1],r[i-1][2]));
            r[i][2] += min(r[i][1],min(r[i-1][1],r[i-1][2]));
        }
        printf("%d. %lld\n",t,r[n-1][1]);
    }
}
