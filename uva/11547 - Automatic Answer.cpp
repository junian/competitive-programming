#include <cstdio>
int main()
{
    int t,i;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&i);
        i = 315*i+36962;
        i *= i<0?-1:1;
        i = (i/10)%10;
        printf("%d\n",i);
    }
    return 0;
}
