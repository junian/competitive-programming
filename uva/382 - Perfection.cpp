#include <cstdio>

int main()
{
    int n;
    puts("PERFECTION OUTPUT");
    while(1)
    {
        scanf("%d", &n);
        if(n<=0)
        {
            puts("END OF OUTPUT");
            break;
        }
        int divsum = n==1?0:1;
        for(int i=2; i*i <= n;i++)
        {
            if(n%i == 0)
            {
                divsum += i;
                int m = n/i;
                if(m != i)
                {
                    divsum += m;
                }
                                    
            }
        }
        
        printf("%5d  ", n);
        if(divsum == n)
        {
            puts("PERFECT");
        }
        else if(divsum > n)
        {
            puts("ABUNDANT");
        }
        else
            puts("DEFICIENT");
    }
    return 0;
}