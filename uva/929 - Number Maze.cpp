#include <cstdio>

int m[1000][1000];
int c[1000][1000];
int a,b;

void trace(int i,int j,int p)
{
    if(i<0 || i>=a || j<0 || j>=b)
        return;
    p=m[i][j]+p;
    if(c[i][j]<0 || p<c[i][j])
        c[i][j]=p;
    else
        return;
    trace(i+1,j,p);
    trace(i-1,j,p);
    trace(i,j+1,p);
    trace(i,j-1,p);
}

int main()
{
    int t,i,j;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&a,&b);
        for(i=0;i<a;i++)
            for(j=0;j<b;j++)
            {
                scanf("%d",&m[i][j]);
                c[i][j]=-1;
            }
        trace(a-1,b-1,0);
        printf("%d\n",c[0][0]);
    }
    return 0;
}
