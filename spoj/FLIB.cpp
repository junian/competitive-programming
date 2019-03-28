#include <cstdio>
#include <map>

using namespace std;

map<long long, int> m,l;

long long f(long long n)
{
    if(n==0)
        return 0;
    if(n==1)
        return 1;
    long long r=m[n];
    if(r==0)
    {
        r = (f(n-1)+f(n-2));//%1000000007;
        m[n]=r;
    }
    return r;
}

long long g(long long n)
{
    if(n==0)
        return 0;
    long long r=l[n];
    if(r==0)
    {
        r=(g(n-1)+f(4*n-1));//%1000000007;
        l[n]=r;
    }
    return r;
}

int main()
{
    int t;
    long long n;
    m.clear();
    l.clear();
    for(t=0;t<20;t++)
        printf("%lld\n",g(t));
    scanf("%d",&t);
    while(t-->0)
    {
        scanf("%lld",&n);
        //for(n=0;n<=2251799813685248;n+=1000)
        printf("%lld\n",g(n%1000000007));
    }
    return 0;
}

