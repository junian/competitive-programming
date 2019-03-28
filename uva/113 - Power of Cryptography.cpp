#include <cstdio>
#include <cmath>

int main()
{
    double a,b,c;
    while(scanf("%lf%lf",&a,&b)!=EOF)
    {
        c = round(exp(log(b)/a));
        printf("%0.0lf\n",c);
    }
    return 0;
}
