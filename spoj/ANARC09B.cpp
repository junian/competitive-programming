#include <cstdio>
long long gcd(long long a, long long b)
{
    if(a == 0)
        return b;
    while (b != 0)
    {
        if(a>b)
            a=a-b;
        else
            b=b-a;
    }
    return a;
}

long long lcm(long long a, long long b)
{
    return (a*b)/gcd(a,b);
}

int main()
{
    long long a,b;
    while(1)
    {
        scanf("%lld%lld",&a,&b);
        if(a<=0 && b<=0)
            break;
        if(a==b)
            puts("1");
        else if(a>b && a%b==0)
            printf("%lld\n",a/b);
        else if(b>a && b%a==0)
            printf("%lld\n",b/a);
        else
            printf("%lld\n",lcm(a,b));
    }
    return 0;
}
