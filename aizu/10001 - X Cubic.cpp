#include<cstdio>
int main()
{
    long long a,b;
    while(scanf("%I64d",&a)!=EOF)
    {
        b=a*a*a;
        printf("%I64d\n",b);
    }
    return 0;
}
