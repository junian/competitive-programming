#include <cstdio>

long long pow2(long long a)
{
    return a*a;
}

int main()
{
    int n,i,j,k;
    long long x[2000],y[2000];
    long long a,b,c,count;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%lld %lld",&x[i],&y[i]);
    count = 0;
    for(i=0;i<n-2;i++)
        for(j=i+1;j<n-1;j++)
            for(k=j+1;k<n;k++)
            {
                a = pow2(x[i]-x[j]) + pow2(y[i]-y[j]);
                b = pow2(x[i]-x[k]) + pow2(y[i]-y[k]);
                c = pow2(x[k]-x[j]) + pow2(y[k]-y[j]);
                if(a+b==c || a+c==b || b+c==a)
                    count++;
            }
    printf("%lld\n",count);
    return 0;
}
