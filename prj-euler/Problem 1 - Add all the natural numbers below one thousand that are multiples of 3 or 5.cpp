#include <cstdio>
int main()
{
    int t=0,i;
    for(i=3;i<1000;i++)
        if(i%3==0 || i%5==0)
            t+=i;
    printf("%d\n",t);
    return 0;
}
