#include <cstdio>

int main()
{
    int a,b,c,d,e;
    while(1)
    {
        scanf("%d%d%d",&a,&b,&c);
        if(a==b && b==c && c==0)
            break;
        d = b-a;
        e = c-b;
        if(d==e)
        {
            printf("AP %d\n",c+d);
        }
        else
        {
            printf("GP %d\n",c*(b/a));
        }
    }
    return 0;
}
