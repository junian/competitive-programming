#include <stdio.h>
#include <math.h>
#define MAX 100000000

int main()
{
    double  p = 0,
            q = 0,
            i = 0,
            j = 0,
            res = 0,
            floor_x = 0,
            ceil_x = 0;
    int t = 0;
    double result = 0.0, x = 0.0, k = 0.0;

    scanf("%d", &t);
    while(t>0)
    {
        t--;
        scanf("%lf", &x);
        scanf("%lf", &k);
        //printf("%d %d\n", x, k);
        result = x / k;
        floor_x = floor(result);
        ceil_x = ceil(result);
        //printf("%lf %lf\n", floor_x, ceil_x);
        for(i = 0.0; i < MAX; i++)
        {
            for(j = 0.0; j < MAX; j++)
            {
                res = i*floor_x + j*ceil_x;
                if(res == x)
                {
                    p = i;
                    q = j;
                    i = MAX;
                    j = MAX;
                }
                else if(res > x)
                {
                    break;
                }
            }
        }
        printf("%0.0lf %0.0lf\n", p, q);
    }
    return 0;
}
