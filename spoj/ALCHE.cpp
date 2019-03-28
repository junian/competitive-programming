#include <cstdio>
int main()
{
    int a,b;
    while(1)
    {
        scanf("%d %d",&a,&b);
        if(a==-1 && b==-1)
            break;
        if(a%1000==0 && b%37==0 && a/1000==b/37)
            printf("Y\n");
        else
            printf("N\n");
    }
    return 0;
}
