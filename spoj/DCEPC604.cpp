#include <cstdio>
#include <cmath>

#define mod 1000000000
#define ll long long int

int five[12] = {5, 25, 125, 625, 3125, 15625, 
     78125, 390625, 1953125, 9765625, 48828125, 244140625};

int fac(int n)
{
    int tot=0;
    for(int i=0; i<12; i++)
    {
        int sub = n/five[i];
        if(sub == 0) break;
        tot += sub;
    }
    return tot;
}

int fact(int n)
{
    return fac(n)%25+1;
}

int fastpow(int n, int p){
    if(p==0)
        return 1;
    if(p&1==0)
        return fastpow(n*n,p>>1);
    return n*fastpow(n*n,p>>1);
}

int farr[11] = {1,1,1,3,3,15,15,105,105,105,105};
ll f(int n){
    if(n<=10)
        return (ll)farr[n];
    return (ll)pow(4,fact(n))*f(n/5)*f(n/10);
}

int main()
{
    int t,n;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        printf("%lld\n", f(n));
    }
}
