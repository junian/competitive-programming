#include <cstdio>
int main()
{
    long long a,b,c,d,e;
    while(scanf("%lld%lld%lld",&a,&b,&c)!=EOF)
    {
        d = a/c + (a%c==0?0:1);
        e = b/c + (b%c==0?0:1);
        printf("%lld\n",d*e);
    }
    return 0;
}
