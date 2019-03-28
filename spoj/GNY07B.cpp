#include <cstdio>
int main()
{
    double p=2.2046,kg=0.4536,g=0.2642,l=3.7854;
    int t,i;
    double x;
    char y[3];
    scanf("%d", &t);
    for(i=1;i<=t;i++)
    {
        scanf("%lf %s", &x, y);
        switch(y[0])
        {
            case 'k':
                printf("%d %0.4lf lb\n", i, x*p);
                break;
            case 'g':
                printf("%d %0.4lf l\n", i, x*l);
                break;
            case 'l':
                if(y[1]=='b')
                {
                    printf("%d %0.4lf kg\n", i, x*kg);
                }
                else
                {
                    printf("%d %0.4lf g\n", i, x*g);
                }
                break;
            default: break;
        }
    }
    return 0;
}
