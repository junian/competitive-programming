#include <cstdio>
int main()
{
    long long n0;
    int k=1;
    while(1)
    {
        scanf("%lld",&n0);
        if(n0<=0)
            break;
        if(n0%2==0)
            printf("%d. even %lld\n",k++,n0/2);
        else
            printf("%d. odd %lld\n",k++,(n0-1)/2);
    }
    return 0;
}
