#include <cstdio>
int main()
{
    int t;
    double n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lf",&n);
        printf("%lf\n",(n*n*n*n-6*n*n*n+23*n*n-18*n+24)/24);
    }
    return 0;
}
