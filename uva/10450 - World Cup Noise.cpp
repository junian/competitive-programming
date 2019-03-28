#include <cstdio>
int main()
{
    unsigned long long int f[52];
    int i,t,n;
    f[0]=1;
    f[1]=2;
    for(i=2;i<=51;i++)
        f[i]=f[i-1]+f[i-2];
    scanf("%d",&t);
    for(n=1;n<=t;n++)
    {
        scanf("%d",&i);
        printf("Scenario #%d:\n%llu\n\n",n,f[i]);
    }
    return 0;
}
