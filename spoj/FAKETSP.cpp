#include <cstdio>
#include <cmath>

int main()
{
    double b,a,c,d,t=0.0;
    char x[9999];
    scanf("%[^(](%lf, %lf).",x,&a,&b);
    while(scanf("%[^(](%lf, %lf).",x,&c,&d)>1)
    {
        t += sqrt((c-a)*(c-a) + (d-b)*(d-b));
        a=c;
        b=d;
        printf("The salesman has traveled a total of %.3lf kilometers.\n",t);
    }
    return 0;
}
