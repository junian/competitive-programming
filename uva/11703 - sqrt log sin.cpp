#include <cstdio>
#include <cmath>

long long x(long long i)
{
    if(i<=0)
        return 1;
    return x(i-sqrt(i)) + x(log(i)) + x(i*sin(i)*sin(i));
}
int main()
{
    long long a;
    while(scanf("%lld",&a),a>=0)
    {
        printf("%lld\n",x(a));
    }
    return 0;
}
