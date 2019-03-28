#include <cstdio>

#define ll long long int

#define MOD 1000000000

int fastpow(int n, int p){
    if(n==0)
        return 0;
    if(p==0)
        return 1;
    if(p&1==0)
        return fastpow(n*n,p>>1);
    return n*fastpow(n*n,p>>1);
}

int farr[11] = {1,1,1,3,3,15,15,105,105,105,105};
ll f(int n)
{
    if(n<=10)
        return (ll) farr[n];
    return (ll) (1<<((n+3)>>2))*f((n+4)/5)*f((n+9)/10);
}

int main()
{
    int t,n;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        printf("%lld\n", f(n));
    }
    return 0;
}
