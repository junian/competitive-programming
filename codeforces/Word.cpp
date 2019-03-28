#include <cstdio>
#include <cstring>

int main()
{
    char s[1000];
    gets(s);
    int ucase,lcase;
    ucase = lcase = 0;
    for(int i=0;s[i]!='\0';i++)
    {
        if(s[i]>='A' && s[i]<='Z')
            ucase++;
        else if(s[i]>='a' && s[i]<='z')
            lcase++;
    }
    if(ucase > lcase)
        for(int i=0;s[i]!='\0';i++)
        {
            if(s[i]>='a' && s[i]<='z')
                putchar(s[i]-'a'+'A');
            else
                putchar(s[i]);
        }
    else
        for(int i=0;s[i]!='\0';i++)
        {
            if(s[i]>='A' && s[i]<='Z')
                putchar(s[i]-'A'+'a');
            else
                putchar(s[i]);
        }
    putchar('\n');
    return 0;
}
