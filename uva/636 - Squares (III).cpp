#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <map>
#include <algorithm>

using namespace std;

unsigned long long power(unsigned long long a, unsigned long long b)
{
    if(b==0)
        return 1;
    if(a==0)
        return 0;
    if(b%2==0)
        return power(a*a,b/2);
    return a*power(a*a,b/2);
}

unsigned long long c;

unsigned long long cbase(char* n, unsigned long long b)
{
    unsigned long long a=0,i;
    long long d;
    d=c-1;
    for(i=0;d>=0;i++)
    {

        a+=(n[d]-'0')*power(b,i);
        d--;
    }
    return a;
}

int main()
{
    char x[1024],y;
    map<unsigned long long, int> m;
    unsigned long long i,a,b;
    m.clear();
    for(i=1;i*i<=1000000000LL;i++)
        m[i*i]=1;
    while(1)
    {
        scanf("%s",x);
        a=strtoull(x,NULL,10);
        if(a<=0)
            break;
        c=strlen(x);
        y=*max_element(x,x+c);
        a=(y-'0')+1;
        for(i=a;i<100;i++)
            if(m[cbase(x,i)]==1)
            {
                printf("%llu\n",i);
                break;
            }
    }
    return 0;
}
