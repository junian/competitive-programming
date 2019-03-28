#include <cstdio>
int main()
{
    unsigned long long y;
    bool /*s=false*/l,h,b;
    while(scanf("%llu",&y)!=EOF)
    {
//        if(s)
//        else
//            s=true;
        l=false;h=false;b=false;
        if((y%4==0 && y%100!=0) || y%400==0)
        {
            l=true;
            printf("This is leap year.\n");
        }
        if(y%15==0)
        {
            h=true;
            printf("This is huluculu festival year.\n");
        }
        if(l && y%55==0)
        {
            b=true;
            printf("This is bulukulu festival year.\n");
        }
        if(!(l|h|b))
            printf("This is an ordinary year.\n");
        printf("\n");
    }
    return 0;
}
