#include <cstdio>

#define ull unsigned long long

int main()
{
    ull a=0,b=0,i;
    for(i=1;i<=100;i++)
        a+=i*i;
    for(i=1;i<=100;i++)
        b+=i;
    b=b*b;
    printf("%llu % llu %llu\n",a,b,b-a);
    return 0;
}
