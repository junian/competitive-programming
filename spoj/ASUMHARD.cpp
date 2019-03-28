#include <cstdio>

#define ll long long int
#define MOD 1234567891

ll power(int a, int b)
{
  ll pow = 1;
  while ( b ) 
  {
         if ( b & 1 ) 
         {
           pow = ((pow%MOD) * (a%MOD))%MOD;
           --b;
         }
         a = ((a%MOD)*(a%MOD))%MOD;
         b = b>>1;
  }
  return pow%MOD;
}

ll f(int n, int k)
{
    ll tot = 0;
    for(int i=1;i<=n;i++)
    {
        tot += (((n-i+1)*power(i,k))%MOD);
    }
    return tot%MOD;
}

int main(){
    int t,n,k;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d%d", &n, &k);
        printf("%lld\n", f(n,k));
    }
    return 0;
}
