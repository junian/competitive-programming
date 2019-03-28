#include <cstdio>

#define MAX 100000

int main()
{
    int n,i;
    long long res;
    long long x[MAX];

    scanf("%d",&n);
    scanf("%lld",&x[0]);
    res = x[0];

    for(i=1;i<n;i++)
    {
        scanf("%lld",&x[i]);
        res ^= x[i];
    }

    printf("%lld\n",res);

    return 0;
}
