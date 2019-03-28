#include <cstdio>
#include <cstring>
long long pow(long long a, char* b, long long c, int n)
{
    if(n<0)
        return 1;
    if(a==0 || a==1)
        return a;
    if(n==0 && b[0]=='0')
        return 1;
    if(b[n]=='2')
        return ((a%c)*(a%c)*(pow(((a%c)*(a%c)*(a%c))%c,b,c,n-1)%c))%c;
    if(b[n]=='1')
        return ((a%c)*(pow(((a%c)*(a%c)*(a%c))%c,b,c,n-1)%c))%c;
    return (pow(((a%c)*(a%c)*(a%c))%c,b,c,n-1)%c)%c;
}

int main()
{
    int t;
    long long a,c;
    char b[256];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld%s%lld",&a,b,&c);
        printf("%lld\n",pow(a,b,c,strlen(b)-1));
    }
    return 0;
}
