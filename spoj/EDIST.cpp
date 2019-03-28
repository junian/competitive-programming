#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
char a[2001],b[2001];
int t[2001][2001];
int main()
{
    int n,i,j,k,l,v;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%s",a);
        scanf("%s",b);
        k=strlen(a);
        l=strlen(b);
        t[0][0]=0;
        for(i=1;i<=k;i++) t[i][0]=i;
        for(j=1;j<=l;j++) t[0][j]=j;
        for(i=1;i<=k;i++)
            for(j=1;j<=l;j++)
            {
                v=(a[i-1]==b[j-1])?0:1;
                t[i][j]=min(t[i-1][j-1]+v,min(t[i-1][j]+1,t[i][j-1]+1));
            }
        printf("%d\n",t[k][l]);
    }
    return 0;
}
