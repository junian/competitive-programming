#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
    int t,n,i,j,m=101,x,y;
    int a[m][m],b[m][m];
    scanf("%d",&t);
    while(t-->0)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
            for(j=0;j<=i;j++)
            {
                scanf("%d",&a[i][j]);
                b[i][j]=0;
            }
        b[0][0]=a[0][0];
        for(i=0;i<n-1;i++)
            for(j=0;j<=i;j++)
            {
                x=b[i][j]+a[i+1][j];
                y=b[i+1][j];
                b[i+1][j]=x>y?x:y;
                x=b[i][j]+a[i+1][j+1];
                y=b[i+1][j+1];
                b[i+1][j+1]=x>y?x:y;
            }
        printf("%d\n",*max_element(b[n-1],b[n-1]+n));
    }
    return 0;
}
