#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
char a[1001],b[1001];
int t[1001][1001];
int main()
{
    int i,j,k,l,v;
    while(1)
    {
        scanf("%s",a);
        scanf("%s",b);
        if(a[0]=='*' && b[0]=='*')
            break;
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
