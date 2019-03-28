#include <cstdio>
int main()
{
    int t,i,a=0;
    scanf("%d",&t);
    while(t-->0)
    {
        scanf("%d",&i);
        if(i>0)a+=i;
    }
    printf("%d\n", a);
    return 0;
}
