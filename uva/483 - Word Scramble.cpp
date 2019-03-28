#include <cstdio>
int main()
{
    int i=0;
    char s[256];
    char x;
    while((x=getchar())!=EOF)
    {
        if(x==' ' || x=='\n')
        {
            while(i--)
                putchar(s[i]);
            i=0;
            putchar(x);
        }
        else
            s[i++]=x;
    }
    return 0;
}
