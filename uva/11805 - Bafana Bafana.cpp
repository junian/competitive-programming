#include <cstdio>

int main()
{
    int a,b,c,t,i;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%d%d%d",&a,&b,&c);
        c=(b+c)%a;
        printf("Case %d: %d\n",i,c==0?a:c);
    }
    return 0;
}
