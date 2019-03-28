#include <cstdio>

long long gcd(long long a, long long b)
{
    if (b == 0)
        return a;
    else
       return gcd(b, a % b);
}

long long lcm(long long a, long long b)
{
    return a*b/gcd(a,b);
}

int main()
{
    long long n,a,b,c,d,e,i;
    while(1)
    {
        scanf("%lld",&n);
        if(n<2)
            break;
        scanf("%lld%lld",&a,&b);
        for(i=2;i<n;i++)
        {
            scanf("%lld%lld",&c,&d);
            e = lcm(b,c);
            a = (e/b)*a;
            d = (e/c)*d;
            b=d;
        }
        e = gcd(a,b);
        printf("%lld %lld\n",a/e,b/e);
    }
    return 0;
}
