#include <cstdio>
int main()
{
    int a,b,d,i;
    char c;
    while(1)
    {
        scanf("%d",&a);
        if(a<=0)
            break;
        while(a--)
        {
            c='*';
            d=0;
            for(i=0;i<5;i++)
            {
                scanf("%d",&b);
                if(b<=127)
                {
                    c='A'+i;
                    d++;
                }
            }
            if(d==1)
                printf("%c\n",c);
            else
                puts("*");
        }
    }
    return 0;
}
