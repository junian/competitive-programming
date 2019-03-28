#include<cstdio>

int main()
{
    long long n,t=0,c=0;
    scanf("%lld",&n);
    while(1)
    {
        if(n/10==0 && n!=7)
            break;
        while(n>0)
        {
            t+=(n%10)*(n%10);
            n=n/10;
        }
        n=t;
        t=0;
        c++;
    }
    if(n%10!=1)
        puts("-1");
    else
        printf("%lld\n",c);
    return 0;
}
