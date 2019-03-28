#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
    long long a[4],b[4],c[4],m;
    int i;
    while(1)
    {
        scanf("%lld%lld%lld%lld%lld%lld%lld%lld",&a[0],&a[1],&a[2],&a[3],&b[0],&b[1],&b[2],&b[3]);
        if(a[0]<0)
            break;
        for(i=0;i<4;i++)
            c[i]=a[i]/b[i] + (a[i]%b[i]>0?1:0);
        m=*max_element(c,c+4);
        for(i=0;i<4;i++)
            a[i]=m*b[i]-a[i];
        printf("%lld %lld %lld %lld\n",a[0],a[1],a[2],a[3]);
    }
    return 0;
}
