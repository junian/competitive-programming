#include <cstdio>
int main()
{
    unsigned long long int f[1001];
    int i;
    f[0]=1;
    f[1]=2;
    for(i=2;i<=1000;i++)
        f[i]=f[i-1]+f[i-2];
    while(scanf("%d",&i)!=EOF)
    {
        printf("%llu\n",f[i]);
    }
    return 0;
}
