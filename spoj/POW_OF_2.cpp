#include <cstdio>
#include <cmath>
int main()
{
    int t;
    unsigned long long x;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%llu",&x);
        if(x > 0 && (x & (x - 1)) == 0)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}

