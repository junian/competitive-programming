#include <cstdio>
#include <cmath>

int main()
{
    double a,b,c,s,l,g;
    int t;
    g=sqrt(3.0);
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lf%lf%lf",&a,&b,&c);
        s=(a+b+c)/2.0;
        l=(((a*a+b*b+c*c)*g)/4.0 + 3.0*sqrt(s*(s-a)*(s-b)*(s-c)))/2.0;
        printf("%.2lf\n",l);
    }
    return 0;
}
