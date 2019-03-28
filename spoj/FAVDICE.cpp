#include <cstdio>
int main()
{
    int t;
    double x,i,y;
    scanf("%d", &t);
    while(t-->0)
    {
        y=0.0;
        scanf("%lf", &x);
        for(i=x;i>=1.0;i-=1.0)
        {
            y+=(x/i);
        }
        printf("%.2lf\n", y);
    }
    return 0;
}
