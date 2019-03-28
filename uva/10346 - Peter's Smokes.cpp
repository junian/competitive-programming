#include <cstdio>
int main()
{
    unsigned long long a,b,c,t;
    while(scanf("%llu%llu",&a,&b)!=EOF)
    {
        t=a;
        while(a>=b)
        {
            c=a/b;
            t+=c;
            a = (a%b) + c;
        }
        printf("%llu\n",t);
    }
    return 0;
}
