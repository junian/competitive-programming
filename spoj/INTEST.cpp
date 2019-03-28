#include <cstdio>
int main()
{
    long long n,k,t,l;
    while(scanf("%lld%lld",&n,&k)!=EOF)
    {
        l=0;
        while(n-->0)
        {
            scanf("%lld",&t);
            if(t%k==0)
                l++;
        }
        printf("%lld\n",l);
    }
    return 0;
}
