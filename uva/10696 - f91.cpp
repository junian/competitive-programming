#include <cstdio>
//#include <map>
//using namespace std;
//map<unsigned long long, unsigned long long> m;
unsigned long long f91(unsigned long long n)
{
    if(n>=101)
        return n-10;
    return 91;
//    if(m[n]!=0)
//        return m[n];
    //return f91(f91(n+11));
//    return m[n];
}

int main()
{
    unsigned long long n;
    while(1)
    {
        scanf("%llu",&n);
        if(n==0)
            break;
        printf("f91(%llu) = %llu\n",n,f91(n));
    }
    return 0;
}
