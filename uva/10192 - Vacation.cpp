#include <cstdio>
#include <cstring>

#define max(a,b) a>b?a:b

int main()
{
    char a[102],b[102];
    int x[102][102];
    int m,n,i,j,k=0;
    while(1)
    {
        gets(a);
        if(a[0]=='#')
            break;
        k++;
        gets(b);
        m=strlen(a);
        n=strlen(b);
        for(i=0;i<=m;i++)
            x[i][0]=0;
        for(j=0;j<=n;j++)
            x[0][j]=0;
        for(i=1;i<=m;i++)
            for(j=1;j<=n;j++)
                x[i][j] = (a[i-1]==b[j-1])?x[i-1][j-1]+1:max(x[i-1][j],x[i][j-1]);
        printf("Case #%d: you can visit at most %d cities.\n",k,x[m][n]);
    }
    return 0;
}
