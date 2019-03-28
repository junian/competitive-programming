#include <cstdio>
#include <algorithm>

using namespace std;

#define MAX 20000
#define LIM 1000000032
int h[MAX];
int diff[MAX];

int main()
{
    int t,k,n,i,m;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&k);
        for(i=0;i<n;i++)
            scanf("%d",&h[i]);
        sort(h,h+n);
        if(k>1)
        {
            m=LIM;
            for(i=0;i<=n-k;i++)
                m = min(m, h[i+k-1]-h[i]);
        }
        else
            m=0;
        printf("%d\n",m);
    }
    return 0;
}
