#include<cstdio>
#include <ctime>
int main()
{
    char m[99];
    int n,t;
    struct tm a;
    scanf("%d",&n);
    while(n-->0)
    {
        scanf("%d",&t);
        a.tm_mon=((t&480)>>5)-1;
        strftime(m,99,"%B",&a);
        printf("%d %s %d\n",t&31,m,t>>9);
    }
    return 0;
}
