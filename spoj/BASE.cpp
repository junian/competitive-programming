#include <cstdio>
#include <cstdlib>

int main()
{
    char x[99],y[99];
    char base[17] = "0123456789ABCDEF";
    int a,b,i;
    long c;
    while(scanf("%s%d%d",x,&a,&b)!=EOF)
    {
        c=strtol(x,NULL,a);
        if(c==0)
        {
            printf("%7s\n","0");
        }
        else
        {
            i=0;
            while(c>=b)
            {
                y[i++]=base[c%b];
                c=c/b;
            }
            y[i++]=base[c];
            y[i]='\0';
            if(i>7)
                printf("%7s\n","ERROR");
            else
            {
                for(c=0;y[c]!='\0';c++)
                    x[i-c-1]=y[c];
                x[i]='\0';
                printf("%7s\n", x);
            }
        }
    }
    return 0;
}
