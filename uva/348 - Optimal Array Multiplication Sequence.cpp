#include <cstdio>
#include <climits>
#define MAX 11
int n;
unsigned long long p[MAX],m[MAX][MAX],s[MAX][MAX];

void mcm()
{
    int i,j,k,l,q;
    for(i=1;i<=n;i++)
        m[i][i]=0;
    for(l=2;l<=n;l++)
    {
        for(i=1;i<=n-l+1;i++)
        {
            j=i+l-1;
            m[i][j]=ULONG_LONG_MAX;
            for(k=i;k<j;k++)
            {
                q=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
                if(q<m[i][j])
                {
                    m[i][j]=q;
                    s[i][j]=k;
                }
            }
        }
    }
}

void print_mcm(int i, int j)
{
    if(i==j)
        printf("A%d",i);
    else
    {
        printf("(");
        print_mcm(i,s[i][j]);
        printf(" x ");
        print_mcm(s[i][j]+1,j);
        printf(")");
    }
}

int main()
{
    int i,j=1;;
    while(scanf("%d",&n),n>0)
    {
        for(i=1;i<=n;i++)
            scanf("%llu%llu",&p[i-1],&p[i]);
        mcm();
        printf("Case %d: ",j++);
        print_mcm(1,n);
        putchar('\n');
    }
    return 0;
}
