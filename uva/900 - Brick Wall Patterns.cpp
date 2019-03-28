#include <cstdio>
int main()
{
    unsigned long long f[52];
    int i;
    f[0]=0;
    f[1]=1;
    f[2]=2;
    for(i=3;i<=50;i++)
        f[i]=f[i-1]+f[i-2];
    while(1)
    {
        scanf("%d",&i);
        if(i<=0)
            break;
        printf("%llu\n",f[i]);
    }
    return 0;
}
