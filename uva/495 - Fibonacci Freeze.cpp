#include <cstdio>

int main()
{
    unsigned long long x[5001];
    int i;
    x[0]=0.0;
    x[1]=1.0;
    for(i=2;i<=5000;i++)
        x[i] = x[i-1]+x[i-2];
    while(scanf("%d",&i)!=EOF)
    {
        printf("The Fibonacci number for %d is %llu\n",i,x[i]);
    }
}
