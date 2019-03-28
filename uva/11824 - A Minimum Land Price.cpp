#include <cstdio>
#include <algorithm>

#define MAX 5000000

using namespace std;

bool cmp(unsigned long long a, unsigned long long b)
{
    return a>b;
}

unsigned long long pow(unsigned long long a, unsigned long long b)
{
    if(b==0)
        return 1;
    if(a==0)
        return 0;
    if(b%2==0)
        return pow(a*a,b/2);
    return a*pow(a*a,b/2);
}

int main()
{
    unsigned long long t,a[50],n,i,j;
    bool ex;
    scanf("%llu",&t);
    while(t--)
    {
        n=0;
        i=0;
        ex=false;
        while(scanf("%llu",&a[i]),a[i++]);
        i--;
        sort(a,a+i,cmp);
        for(j=0;j<i;j++)
        {

            n+=2*pow(a[j],j+1);
            if(n>MAX)
            {
                ex=true;
                break;
            }
        }
        if(ex)
            puts("Too expensive");
        else
            printf("%llu\n",n);
    }
    return 0;
}
