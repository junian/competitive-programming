#include <cstdio>
int main()
{
    long long f[72];
    int i,t;
    f[0]=0;
    f[1]=1;
    for(i=2;i<72;i++)
        f[i]=f[i-1]+f[i-2];
    scanf("%d",&t);
    while(t-->0)
    {
        scanf("%d",&i);
        printf("%lld\n",f[i]);
    }
    return 0;
}
