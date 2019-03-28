#include <cstdio>
int main()
{
    unsigned int t,a,b,c,n,s;
    scanf("%d",&t);
    while(t-->0)
    {
        s=0;
        scanf("%u",&n);
        while(n-->0)
        {
            scanf("%u%u%u",&a,&b,&c);
            s+=a*c;
        }
        printf("%u\n",s);
    }
    return 0;
}
