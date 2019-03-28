#include <cstdio>
#include <cmath>
int main()
{
    float x;
    float pi = acos(-1);
    while(1)
    {
        scanf("%f",&x);
        if(x<=0.0f)
            break;
        printf("%.2f\n",(x*x)/(2.0f*pi));
    }
    return 0;
}
