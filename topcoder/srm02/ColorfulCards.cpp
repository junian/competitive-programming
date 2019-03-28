#include <cstdio>

int main()
{
    bool *notPrime = new bool[1001];
    printf("0,0,1");
    for(int i=3;i<=1000;i++)
    {
        if(!notPrime[i] && i%2!=0)
        {
            printf(",1");
            for(int j=2*i;j<=1000;j+=i)
                notPrime[j] = true;
        }
        else
            printf(",0");
    }
    return 0;
}
