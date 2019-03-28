#include <cstdio>
#define M 1000000007
#define MAX 100000LL

int main()
{
    long long a,b[MAX+1];
    long long i,t;
    b[0]=0;
    b[1]=b[2]=1;
    for(i=3;i<=MAX;i++)
        b[i] = ((b[i-1]%M) * (((i * (i-1)) / 2) % M)) % M;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld",&i);
        printf("%lld\n", b[i]);
    }
    return 0;
}
