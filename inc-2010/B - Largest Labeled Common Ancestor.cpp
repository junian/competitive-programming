#include <cstdio>

int main()
{
    int a,b,k,t;
    scanf("%d",&t);
    while(t--)
    {

        scanf("%d%d%d",&k,&a,&b);
        a--;
        b--;
        while(a != b)
        {
            if(a < b)
                b = (b-1)/k;
            else
                a = (a-1)/k;
        }
        printf("%d\n",a+1);
    }
    return 0;
}
