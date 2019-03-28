#include <cstdio>
int main()
{
    long long t,n,m;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld%lld",&m,&n);
        if(m>n)
        {
            if(n%2==0)
                puts("U");
            else
                puts("D");
        }
        else
        {
            if(m%2==0)
                puts("L");
            else
                puts("R");
        }
    }
    return 0;
}
