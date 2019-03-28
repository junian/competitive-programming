#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
    long long tab[100][10];
    long long max[100];
    int n,m,t,i,j,k;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d",&n,&m,&k);
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
                scanf("%lld",&tab[i][j]);
            max[i] = (long long*)max_element(tab[i], tab[i]+m) - tab[i];
        }
        for(i=0;i<n;i++)
        {
            printf("%d\n", max[i]);
        }
    }

    return 0;
}
