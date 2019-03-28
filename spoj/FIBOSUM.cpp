#include <cstdio>
#include <cmath>
#include <algorithm>

#define M 1000000007

using namespace std;

typedef long long ll;

int power(int n, int p)
{
    if(p==0)
        return 1;
    if(n==0)
        return 0;
    if(p%2==0)
        return pow(n*n,p/2);
    return n*pow(n*n,p/2);
}

ll fibo(int n)
{
    if(n<=0)
        return 0;
    if(n==1 || n==2)
        return 1;
    ll f=1, l=1, sign = -1, lim = floor(log(n)/log(2));
    ll mask = power(2,lim-1), i,temp;
    for(i=1;i<lim;i++)
    {
        temp = ((f%M)*(f%M))%M;
        f = (f+l)>>1%M;
        f = (( 2*((f%M)*(f%M)) % M ) - ( (3*temp) % M ) - 2*sign) % M;
        l = (((5*temp) % M ) + 2*sign) % M;
        sign = 1;
        if((n & mask) != 0)
        {
            temp = f;
            f = ((f+l)>>1) % M;
            l = (f+2*temp) % M;
            sign = -1;
        }
        mask = mask / 2;
    }
    if((n & mask) == 0)
        f = ((f%M)*(l%M)) % M;
    else
    {
        f = ((f+l)>>1) % M;
        f = ((f%M)*(l%M)-sign) % M;
    }
    return f%M;
}

ll fibo2(int n)
{
    if(n<=0)
        return 0;
    if(n<=2)
        return 1;
    int i;
    ll a=1,b=1,c=0;
    for(i=3;i<=n;i++)
    {
        c = ((a%M)+(b%M))%M;
        a=b;
        b=c;
    }
    return b;
}

int main()
{
    int t,i;
    int m,n;
    ll tot;
//    printf("%d\n",__gcd(M,2));
    for(i=0;i<=100;i++)
        printf("%d %d\n",i,fibo(i));
    puts(" ");
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        tot = (fibo(m + 2) - fibo(n + 1))%M;
        printf("%I64d\n",tot);
    }

    return 0;
}
