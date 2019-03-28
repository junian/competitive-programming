#include <cstdio>
int main()
{
    unsigned long long n,a,b;
    int i=0;
    while(scanf("%llu",&n)!=EOF)
    {
        i++;
        printf("%4d.",i);
        if(n==0)
        {
            printf(" 0\n");
        }
        else
        {
            a=n/100000000000000LL;
            if(a>0)
                printf(" %llu kuti",a);
            a=n/10000000;
            if(a>0)
            {
                a=a%10000000;
                b=a/100000;
                if(b>0)
                    printf(" %llu lakh",b);
                b=(a%100000)/1000;
                if(b>0)
                    printf(" %llu hajar",b);
                b=(a%1000)/100;
                if(b>0)
                    printf(" %llu shata",b);
                b=a%100;
                if(b>0)
                    printf(" %llu",b);
                printf(" kuti");
            }
            a=n%10000000;
            b=a/100000;
            if(b>0)
                printf(" %llu lakh",b);
            b=(a%100000)/1000;
            if(b>0)
                printf(" %llu hajar",b);
            b=(a%1000)/100;
            if(b>0)
                printf(" %llu shata",b);
            b=a%100;
            if(b>0)
                printf(" %llu",b);
            printf("\n");
        }
    }
    return 0;
}
