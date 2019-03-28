#include <cstdio>

int main()
{
    int t;
    unsigned long long n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%llu",&n);
        printf("%llu\n",(n*(n+2)*(2*n+1))/8);
    }
    return 0;
}
