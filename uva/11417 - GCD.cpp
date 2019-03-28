#include <cstdio>

int g[502][502];

int gcd(int a, int b)
{
    if(a == 0)
        return b;
    if(g[a][b]!=0)
        return g[a][b];
    if(g[b][a]!=0)
        return g[b][a];
    int x=a,y=b;
    while (b != 0)
    {
        if(a>b)
            a=a-b;
        else
            b=b-a;
    }
    g[x][y]=a;
    g[y][x]=a;
    return a;
}

int main()
{
    int i,j;
    for(i=0;i<=501;i++)
        for(j=0;j<=501;j++)
            g[i][j]=0;
    int n,g;
    while(1)
    {
        scanf("%d",&n);
        if(n==0)
            break;
        g=0;
        for(i=1;i<n;i++)
            for(j=i+1;j<=n;j++)
                g+=gcd(i,j);
        printf("%d\n",g);
    }
    return 0;
}
