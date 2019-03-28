#include <cstdio>

#define max(a,b) a>b?a:b

int main()
{
    int t,i,j,k,n,m,a[64][64];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                scanf("%d",&a[i][j]);
        m=0;
        for(i=0;i<n-2;i++)
            for(j=i+1;j<n-1;j++)
                for(k=j+1;k<n;k++)
                    m = max(m, a[i][j]*a[i][k]*a[j][k]);
        printf("%d\n",m);
    }
    return 0;
}
