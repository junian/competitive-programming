#include <cstdio>
#include <cmath>
int main()
{
    char *a="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    double sn,D,x2;
    int x;
    while(scanf("%lf",&sn)!=EOF)
    {
        if(sn==0.0)break;
        D=1-8*(-sn);
        D=sqrt(D);
//        x1=(-1-D)/2;
//        printf("%lf\n",ceil(x1));
        x2=ceil((-1+D)/2);
//        printf("%lf\n",ceil(x2));
        x=(int)x2;
        x=(x-1)%26;
        printf("TERM %0.0lf IS %c\n",sn,a[x]);
    }
    return 0;
}
