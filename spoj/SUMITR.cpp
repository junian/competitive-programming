#include<cstdio>
#define x for(j=0;j<=i;j++)
main(){int t=100,n,i,j,a[t][t];scanf("%d",&t);while(t--){scanf("%d",&n);for(i=0;i<n;i++)x scanf("%d",&a[i][j]);for(i=n-2;i>=0;i--)x a[i][j]+=a[i+1][j]>a[i+1][j+1]?a[i+1][j]:a[i+1][j+1];printf("%d\n",**a);}}
