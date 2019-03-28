#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

long long power(long long a, long long b)
{
    if(a==0)
        return 0;
    if(b==0)
        return 1;
    if(b%2!=0)
        return a*power(a*a,b/2);
    return power(a*a,b/2);
}
int main()
{
    char a[16],b[16];
    long long c,d,t,x,y,la,lb,i;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%s%s",a,b);
        la=strlen(a);
        lb=strlen(b);
        c = (long long)*max_element(a,a+la);
        d = (long long)*max_element(b,b+lb);

        x=0;
        if(c!='0')
        {
            c=(c-'0')+1;
            for(i=0;i<la;i++)
                x+=(a[la-i-1]-'0')*power(c,i);
        }
        y=0;
        if(d!='0')
        {
            d=(d-'0')+1;
            for(i=0;i<lb;i++)
                y+=(b[lb-i-1]-'0')*power(d,i);
        }
        printf("%lld\n",x+y);
    }
    return 0;
}
