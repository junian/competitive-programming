#include <cstdio>
#define M 1000000007LL
#include <cmath>

unsigned long long power(unsigned long long n, unsigned long long p)
{
    if(p==0)
        return 1;
    if(n==0)
        return 0;
    if(p%2==0)
        return power((n*n)%M, p/2) % M;
    return (n*power((n*n)%M, p/2)) % M;
}

unsigned long long f(unsigned long long a, unsigned long long k)
{
    unsigned long long tot=0,i,t;
    for(i=1;i*i<=a;i++)
    {
        if(a%i==0)
        {
            tot = (tot%M + power(i,k)%M)%M;
            t=a/i;
            if(t!=i)
                tot = (tot%M + power(t,k)%M)%M;
        }
    }
    return tot;
}

unsigned long long g(unsigned long long a, unsigned long long b, unsigned long long c)
{
    unsigned long long i,j,k,t,tot=0;
    for(i=a;i<=b;i++)
    {
        tot = (tot%M + f(i,c)%M)%M;
    }
    return tot;
}

int main()
{
    unsigned long long t,a,b,c;
    scanf("%llu",&t);
    while(t--)
    {
        scanf("%llu%llu%llu",&a,&b,&c);
        printf("%llu\n",g(a,b,c));
    }
    return 0;
}
