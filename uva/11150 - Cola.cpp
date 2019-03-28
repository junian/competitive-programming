#include <cstdio>
int main()
{
    int n,t=0;
    while(scanf("%d",&n)!=EOF)
    {
        t=n;
        n+=2;
        while(n>3)
            t+=n/3,n=(n/3)+(n%3);
        printf("%d\n",t);
    }
    return 0;
}
