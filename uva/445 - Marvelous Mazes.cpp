#include <cstdio>

int main()
{
    char x;
    int n=0,i;
    while((x=getchar())!=EOF)
    {
        if(x=='!' || x=='\n')
            putchar('\n');
        else if(x>='0' && x<='9')
            n=n+(x-'0');
        else if(x=='b')
        {
            for(i=0;i<n;i++)
                putchar(' ');
            n=0;
        }
        else if(x!=' ')
        {
            for(i=0;i<n;i++)
                putchar(x);
            n=0;
        }
    }
    return 0;
}
