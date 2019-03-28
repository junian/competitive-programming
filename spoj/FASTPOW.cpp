#include <cstdio>

long long modPow(long long a, long long b, long long c)
{
    if(b==0)
        return 1;
    if(a==0)
        return 0;
    if(b%2==0)
        return modPow(((a%c)*(a%c))%c,b/2,c)%c;
    return ((a%c)*(modPow(((a%c)*(a%c))%c,b/2,c)%c))%c;
}
int main()
{
    long long a,b,c;
    while(scanf("%lld%lld%lld",&a,&b,&c)!=EOF)
        printf("%lld\n",modPow(a,b,c));
    return 0;
}
