#include <cstdio>
#include <cstdlib>
#include <cstring>

int main()
{
    int o,p,q,i;
    char x[100001],y[100001];
    while(1)
    {
        scanf("%s%s",x,y);
        if(x[0]=='*' && y[0]=='*')
            break;
        o=strlen(x);
        p=strlen(y);
        if(o>p)
        {
            q=o-p;
            memmove(y+q,y,p);
            for(i = 0; i < q; i++ )
                y[i] = '0';
        }
        else if(o<p)
        {
            q=p-o;
            memmove(x+q,x,o);
            for(i = 0; i < q; i++ )
                x[i] = '0';
        }
        i=strcmp(x,y);
        if(i==0)
            printf("=\n");
        else if(i<0)
            printf("<\n");
        else
            printf(">\n");
    }
    return 0;
}
