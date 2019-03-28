#include <cstdio>

unsigned long long power(unsigned long long n, unsigned long long p, unsigned long long m)
{
    if(p==0)
        return 1;
    if(n==0)
        return 0;
    if(p%2==0)
        return power((n*n)%m, p/2, m) % m;
    return (n*power((n*n)%m, p/2, m)) % m;
}

int main()
{
    unsigned long long b,p,m,i,c;
    while(scanf("%llu%llu%llu",&b,&p,&m)!=EOF)
    {
        c=power(b,p,m);
        printf("%llu\n",c);
    }
    return 0;
}
