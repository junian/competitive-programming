#include <cstdio>
#include <cmath>
int main()
{
    double pi = acos(-1);
    double a,b;
    double pi2 = pi*pi;
    long long c,d;
    while(1)
    {
        scanf("%lf%lf",&a,&b);
        if(a==0.0 && b==0.0)
            break;
        c = (long long) (3.0*a*a/pi2);
        printf("%lld\n",c);
    }
    return 0;
}
