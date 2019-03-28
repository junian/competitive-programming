#include<cstdio>
#include<map>

using namespace std;

map<int, long long> h;

long long max(int a, long long b)
{
    if(b>a)
        return b;
    return a;
}

long long f(int n)
{
    if (n == 0) return 0;
    long long r = h[n];
    if (r == 0)
    {
        r = max( n , f(n/2)+f(n/3)+f(n/4));
        h[n] = r;
    }
    return r;
}

int main()
{
    unsigned int a;
    h.clear();
    while(scanf("%u",&a)!=EOF)
    {
        printf("%u\n", f(a));
    }
    return 0;
}
