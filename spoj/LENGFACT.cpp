#include <cstdio>
#include <cmath>
int main()
{
    double u;
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lf",&u);
        if(u<=3.0)
            printf("1\n");
        else
            printf("%.0lf\n",ceil((u*log(u)-u+log(2*acos(-1)*u)/2)/log(10)));
    }

    return 0;
}

