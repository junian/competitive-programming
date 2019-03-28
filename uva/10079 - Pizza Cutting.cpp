#include <cstdio>
int main()
{
    long long n;
    unsigned long long x;
    while(1)
    {
        scanf("%lld",&n);
        if(n<0)
            break;
        x = 2 + ((n+2)*(n-1))/2;
        printf("%llu\n",x);
    }
    return 0;
}
