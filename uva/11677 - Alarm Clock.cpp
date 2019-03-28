#include <cstdio>

int main()
{
    int min = 24*60;
    int a,b,c,d;
    while(scanf("%d%d%d%d",&a,&b,&c,&d),a|b|c|d)
    {
        a = a*60 + b;
        b = c*60 + d;
        printf("%d\n",(b+(min-a))%min);
    }
    return 0;
}
