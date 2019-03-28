#include <cstdio>

#define MAX 10000

int main()
{
    int primeFactors[MAX];
    int n,i,a,b,c;
    while(1)
    {
        scanf("%d",&b);
        a=b;
        if(a<1)
            break;
        n=0;
        c=1;
        i=2;
        while(i*i<=b && a!=0)
        {
            if(a%i==0)
            {
                while(a%i==0)
                {
                    primeFactors[n++] = i;
                    a/=i;
                }
            }
            if(b%i==0)
                c++;
            i++;
        }
        if(a!=1)
            primeFactors[n++] = a;
        printf("%d = %d",b,primeFactors[0]);
        for(i=1;i<n;i++)
            printf(" * %d",primeFactors[i]);
        printf("\nWith %d marbles, %d different rectangles can be constructed.\n",b,c);
    }
    return 0;
}
