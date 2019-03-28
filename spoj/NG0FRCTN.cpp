#include <cstdio>
int main()
{
    long long n,l,st[128],a,b;
    while(1)
    {
        scanf("%lld",&n);
        if(n<=0)
            break;
        n--;
        l=0;
        while(n>0)
        {
            st[l++] = n;
            n = (n-1)/2;
        }
        l--;
        a=1;b=1;
        while(l>=0)
        {
            n = n*2+1;
            if(n==st[l--])
            {
                b = a+b;
            }
            else
            {
                a = a+b;
                n++;
            }
        }
        printf("%lld/%lld\n",a,b);
    }
    return 0;
}
