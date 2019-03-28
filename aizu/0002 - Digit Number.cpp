#include <cstdio>

int main()
{
    int a,b;
    while(scanf("%d%d",&a,&b)!=EOF)
    {
        b = a+b;
        a=0;
        while(b>0)
        {
            b/=10;
            a++;
        }
        printf("%d\n",a);
    }
    return 0;
}
