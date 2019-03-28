#include <cstdio>
int main()
{
    long long x,y,z,t,i;
    scanf("%lld",&t);
    while(t-->0)
    {
        scanf("%lld",&x);
        y=0;
        for(i=0;i<x;i++)
        {
            scanf("%lld",&z);
            y = (y+z)%x;
        }
        if(y==0)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
