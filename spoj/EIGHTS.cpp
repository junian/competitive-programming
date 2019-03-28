#include <cstdio>
int main()
{
    unsigned long long n;
    int t;
//    for(n=2;n<=3000;n+=10)
//        if(n*n*n%1000 == 888)
//            printf("[%llu - %llu]\n",n,n*n*n);
    scanf("%d",&t);
    while(t--)
    {
        scanf("%llu",&n);
        printf("%llu\n",192+250*(n-1));
    }
    return 0;
}
