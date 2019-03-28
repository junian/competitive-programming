#include <cstdio>

int max,m,n,x,y;
int p[21][21];
int pp[21][21];

void trace(int point, int i, int j)
{
    if(pp[i][j]>point || pp[i][j]==0)
        pp[i][j]=point;
    else
        return;
    if(i==x && j==y)
        return;
    if(i-1>=0)
        trace(p[i-1][j]+pp[i][j],i-1,j);
    if(j-1>=0)
        trace(p[i][j-1]+pp[i][j],i,j-1);
}

int main()
{
    int i,j;
    scanf("%d %d",&m,&n);
    scanf("%d %d",&x,&y);
    max=-1;
    x--;y--;

    for(i=0;i<21;i++)
        for(j=0;j<21;j++)
            pp[i][j]=0;
    for(i=0;i<m;i++)
        for(j=0;j<n;j++)
            scanf("%d",&p[i][j]);

    trace(p[m-1][n-1],m-1,n-1);
//    for(i=0;i<m;i++)
//    {
//        for(j=0;j<n;j++)
//            printf("%d ",pp[i][j]);
//        printf("\n");
//    }
//    max=pp[x+1][y]<pp[x][y+1]?pp[x+1][y]:pp[x][y+1];
//    printf("%d\n",max);
    max=2*p[x][y]-pp[x][y];
    if(max<0)
        printf("N\n");
    else
        printf("Y %d\n", max);
    return 0;
}
