#include <cstdio>
int main()
{
    long long a,b,c;
    int i,t;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%lld%lld%lld",&a,&b,&c);
        printf("Case %d: ",i);
        if(!(a>0 && b>0 && c>0 && a+b>c && a+c>b && b+c>a))
            printf("Invalid\n");
        else if(a==b && a==c)
            printf("Equilateral\n");
        else if(a==b || a==c || b==c)
            printf("Isosceles\n");
        else
            printf("Scalene\n");
    }
    return 0;
}
