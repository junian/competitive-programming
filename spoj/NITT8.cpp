#include <cstdio>
#include <algorithm>
#define MAX 100032
#define lli long long int
using namespace std;

typedef struct cewek
{
    int x,y;
};

cewek a[MAX],b[MAX],qu[MAX];

bool cmp(cewek a, cewek b)
{
    if(a.y==b.y)
        return a.x<b.x;
    return a.y<b.y;
}

int main()
{
    int n,t;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        for(int i=0;i<n;i++)
        {
            scanf("%d", &a[i].y);
            a[i].x=i;
        }
        sort(a,a+n, cmp);
        lli maxx = 0L;
        int front=0, end=0;
        qu[end++] = a[n-1];
        int ind = n-2;
        while(ind>=0)
        {
            lli maxi = min(a[ind].y, qu[front].y)*abs(a[ind].x-qu[front].x);
            if(maxx < maxi)
                maxx = maxi;
            else
                front++;
            qu[end++] = a[ind];
            ind--;
        }
        printf("%lld\n", maxx);
        maxx = 0L;
        for(int i=0;i<n-1;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                lli maxi = min(a[i].y, a[j].y)*abs(a[i].x-a[j].x);    
                if(maxi>maxx)
                    maxx=maxi;
            }
        }
        printf("%lld\n", maxx);
    }    
    return 0;
}
