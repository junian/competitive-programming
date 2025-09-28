#include <stdio.h>

int hcf(int a, int b)
{
    if(b==0)
        return a;
    else
        return hcf(b, a % b);
}

int main()
{
    int t;
    scanf("%d", &t);
    int a, b;
    while(t>0)
    {
        t--;
        scanf("%d %d", &a, &b);
        printf("%d", hcf(a, b));
    }
    return 0;
}
