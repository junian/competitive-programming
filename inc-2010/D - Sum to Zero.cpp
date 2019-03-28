#include <cstdio>
#include <algorithm>

using namespace std;

int a[3][2010],d[2010][2010];

bool cmp(int a, int b)
{
    return b<a;
}

bool search(int i, int j, int p, int n)
{
    if(i>=n || j>=n)
        return false;
    if(p==d[i][j])
        return true;
    if(p<d[i][j])
        return search(i,j+1,p,n);
    return search(i+1,j,p,n);
}

int main()
{
    int t,i,j,n;
    long long k;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(i=0;i<3;i++)
            for(j=0;j<n;j++)
                scanf("%d",&a[i][j]);
        sort(a[0],a[0]+n);
        sort(a[1],a[1]+n,cmp);
        sort(a[2],a[2]+n);
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                d[i][j] = a[0][i]+a[1][j];
        k=0;
        for(i=0;i<n;i++)
            if(search(0,0,-a[2][i],n))
                k++;
        printf("%lld\n",k);
    }
    return 0;
}
