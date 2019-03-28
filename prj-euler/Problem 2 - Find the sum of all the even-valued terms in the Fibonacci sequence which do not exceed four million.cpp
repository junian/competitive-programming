#include <cstdio>
int main()
{
    int a=0,b=1,c=1,d=0;
    while(b<4000000)
    {
        if(b%2==0)
            d+=b;
        c=a+b;
        a=b;
        b=c;
    }
    printf("%d\n",d);
    return 0;
}
