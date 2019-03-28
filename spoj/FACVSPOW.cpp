#include<cmath>
#include <cstdio>
long long tb[1000001];
int main()
{
    double pi = acos(-1);
    long long i,x=0,h;
    double u=2.0;
    for(i=2;i<=1000000;i++)
    {
        while(x<=i)
        {
            x = (long long) ceil(exp((u*log(u)-u+log(2*pi*u)/2)/u));
            h = (long long) u;
            u += 1.0;
        }
        tb[i] = h;
    }
    int t,a;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&a);
        printf("%lld\n",tb[a]);
    }
    return 0;
}
