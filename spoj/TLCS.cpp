#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
int main()
{
    char x[1001];
    char y[1001];
    int a[1001];
    int b[1001];
    char c[1001];
    int m,n,t,i,j,k,d;
    int **l=(int**)malloc(sizeof(int*)*1001);
    for(i=0;i<1001;i++)
        l[i]=(int*)malloc(sizeof(int)*1001);
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%d %s", &m, x);
        scanf("%d %s", &n, y);
        for(j=0;j<=m;j++)
            l[j][0]=0;
        for(j=0;j<=n;j++)
            l[0][j]=0;
        for(j=1;j<=m;j++)
        {
            for(k=1;k<=n;k++)
            {
                if(x[j-1] == y[k-1])
                {
                    l[j][k] = l[j-1][k-1]+1;
                }
                else
                {
                    l[j][k] = max(l[j][k-1],l[j-1][k]);
                }
            }
        }
        if(l[m][n]<=1)
        {
            printf("case %d N\n", i);
        }
        else
        {
            printf("case %d Y\n%d\n", i, l[m][n]);
            j=m;
            k=n;
            d=l[m][n]-1;
            while(l[j][k]!=0)
            {
                if(x[j-1]==y[k-1])
                {
                    c[d]=x[j-1];
                    a[d]=j;
                    b[d]=k;
                    d--;
                    j--;
                    k--;
                }
                else if(l[j][k-1]>l[j-1][k])
                    k--;
                else
                    j--;
            }
        }
        if(l[m][n]>1)
        for(d=0;d<l[m][n];d++)
            printf("%c %d %d\n", c[d], a[d], b[d]);
    }
    return 0;
}
