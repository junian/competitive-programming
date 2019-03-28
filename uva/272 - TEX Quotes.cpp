#include <cstdio>

int  main()
{
    char x;
    bool first=true;
    while((x=getchar())!=EOF)
    {
        if(x=='\"')
        {
            if(first)
                printf("``");
            else
                printf("''");
            first = !first;
        }
        else
        putchar(x);
    }
    return 0;
}
