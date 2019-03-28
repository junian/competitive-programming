#include <cstdio>

int rev(int n)
{
    int r=0;
    while(n>0)
    {
        r=(r*10+(n%10));
        n=n/10;
    }
    return r;
}

int main()
{
    int t,a,b;
    scanf("%d",&t);
    while(t-->0)
    {
        scanf("%d%d",&a,&b);
        printf("%d\n",rev(rev(a)+rev(b)));
    }
    return 0;
}
