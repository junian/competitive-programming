#include <cstdio>

int main()
{
    int t,a,n,d;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d",&n,&a,&d);
        printf("%d\n",((2*a+(n-1)*d)*n)/2);
    }
    return 0;
}
