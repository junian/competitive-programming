#include <cstdio>

typedef unsigned long long ll;

ll gcd(ll a, ll b)
{
    if(b==0)
        return a;
    return gcd(b, a%b);
}

int main()
{
    ll lcm,a,b,gcl;
    while(scanf("%I64u %I64u",&a,&b)!=EOF)
    {
        gcl = gcd(a,b);
        lcm = (a*b)/gcl;
        printf("%I64u %I64u\n",gcl,lcm);
    }
    return 0;
}
