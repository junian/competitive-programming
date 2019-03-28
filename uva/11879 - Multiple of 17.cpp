#include <cstdio>
int main()
{
    int n,c;
    while(scanf("%d",&n),n)
    {
        c=(n%10)*5;
        n=n/10;
        c=n-c;
        c*=c<0?-1:1;
        if(c%17==0)
            puts("1");
        else
            puts("0");
    }
    return 0;
}
