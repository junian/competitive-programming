#include <stdio.h>

int main()
{
    int n;
    float m;
    scanf("%d %f", &n, &m);
    if(n%5!=0 || n+0.5>m)
        printf("%.2f\n", m);
    else
        printf("%.2f\n", m-(n+0.5));
    return 0;
}
