#include <cstdio>
#include <cstring>

int length(int a)
{
    if(a == 0)
        return 1;
    int n=0;
    while(a!=0)
    {
        n++;
        a/=10;
    }
    return n;
}

int main()
{
    char s[1000024];
    int a,b,c,i;
    while(true)
    {
        gets(s);
        if(s[0] == 'E')
            break;

        a = strlen(s);
        if(a==1 && s[0]=='1')
            puts("1");
        else
        {
            b = length(a);
            i = 2;
            while(b!=a)
            {
                i++;
                c = length(b);
                a = b;
                b = c;
            }
            printf("%d\n",i);
        }
    }
    return 0;
}
