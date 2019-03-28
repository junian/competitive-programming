#include <cstdio>
#include <algorithm>
#define MAX 4002
#define MMAX 16000032
using namespace std;
int a[MAX],b[MAX],c[MAX],d[MAX];
int s1[MMAX],s2[MMAX];
int main()
{
    long long cn=0;
    int lim=0,t,i,j,k;
    scanf("%d",&t);
    for(i=0;i<t;i++)
        scanf("%d%d%d%d",&a[i],&b[i],&c[i],&d[i]);
    for(i=0;i<t;i++)
        for(j=0;j<t;j++)
        {
            s1[lim]=a[i]+b[j];
            s2[lim++]=c[i]+d[j];
        }
    sort(s2,s2+lim);
    pair<int*, int*> f;
    for(i=0;i<lim;i++)
    {
        f=equal_range(s2, s2+lim, -s1[i]);
        cn+=f.second-f.first;
    }
    printf("%lld\n",cn);
    return 0;
}
