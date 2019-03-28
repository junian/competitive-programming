#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
    int turu=1;
    int a[2]={0,0},
        b[2]={0,0},
        t=0,n;
    scanf("%d",&n);
    n--;
    scanf("%d%d",&a[turu],&b[turu]);
    t+=b[turu];
    while(n--)
    {
        turu=!turu;
        scanf("%d%d",&a[turu],&b[turu]);
        t+=max(b[turu]+b[!turu]-a[])
    }
    printf("%d\n",t);
    return 0;
}
