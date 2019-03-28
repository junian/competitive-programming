#include <cstdio>
int main()
{
    long long int a,b,c,d;
    char s[128];
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d %I64d %I64d %s", &a,&b,&c,&d, s);
        if(s[0] == 'b')
        {
            long long bayar = d;
            long long keluar = a*b*c;
            printf("%I64d\n", bayar-keluar);
        }
        else
            printf("-%I64d\n", a*b*c);
    }
    return 0;
}
