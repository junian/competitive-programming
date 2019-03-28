#include <cstdio>
int main()
{
    int n,i,j;
    int x[10001];
    x[0]=0;
    for(i=1;i<=10000;i++)
        x[i]=1;
    for(i=2;i<=100;i++)
        for(j=i*i;j<=10000;j+=i)
            x[j]++;
    for(i=2;i<=10000;i++)
        x[i]+=x[i-1];
    scanf("%d",&n);
    printf("%d\n",x[n]);
    return 0;
}
