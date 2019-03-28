#include <cstdio>

int main()
{
    int a,b,c,t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d",&a,&b,&c);
        if(a*a+b*b==c*c || a*a+c*c==b*b || b*b+c*c==a*a)
            printf("YES\n");
        else
            puts("NO");
    }
    return 0;
}
