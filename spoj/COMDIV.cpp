#include <cstdio>
#include <cstdlib>

#define MAX 1000000

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    else
       return gcd(b, a % b);
}

int x(int a)
{
    int i,t=0;
    for(i=1;i*i<=a;i++)
    {
        if(a%i==0)
            if(a/i!=i)
                t+=2;
            else
                t++;
    }
    return t;
}

int main()
{
    int i,j,t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&i,&j);
        printf("%d\n",x(gcd(i,j)));
    }
    return 0;
}
