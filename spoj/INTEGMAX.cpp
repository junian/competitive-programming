#include <cstdio>
#include <algorithm>

using namespace std;

#define MAX 10000

int main()
{
    double x[MAX+32], y[MAX+32], l[MAX+32], h[MAX+32];
    double luas;
    int n,i,j,k;
    while(1)
    {
        scanf("%d",&n);
        if(n<0)
            break;
        luas = 0.0;
        for(i=0;i<n;i++)
            scanf("%lf",&x[i]);
        for(i=0;i<n;i++)
            scanf("%lf",&h[i]);
        sort(h,h+n);
        j=n/2;
        k=j-1;
        for(i=n-1;i>=0;i--)
        {
            if(i%2==0)
                y[j++]=h[i];
            else
                y[k--]=h[i];
        }
        for(i=1;i<n;i++)
        {
            l[i-1] = x[i]-x[i-1];
            h[i-1] = y[i]+y[i-1];
        }
        sort(l,l+n-1);
        sort(h,h+n-1);
        for(i=0;i<n-1;i++)
            luas += (l[i]*h[i]);
        printf("%.1lf\n",0.5*luas);
    }
    return 0;
}
