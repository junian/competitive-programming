#include <cstdio>
#include <cstring>
#include <cstdlib>
int main()
{
    char x[256];
    long long y;
    while(1)
    {
        scanf("%s",x);
        if(strlen(x)>=2 && x[1]=='x')
        {
            y = strtoll(x,NULL,16);
            printf("%lld\n",y);
        }
        else
        {
            y=strtoll(x,NULL,10);
            if(y<0)
                break;
            sprintf(x,"%#X",y);
            x[1]='x';
            puts(x);
        }
    }
    return 0;
}
