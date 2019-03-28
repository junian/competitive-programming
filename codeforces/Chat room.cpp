#include <cstdio>

int main()
{
    char s[1000];
    char *hello = "hello";
    int n=0;
    gets(s);
    for(int i=0; s[i]!='\0' && n<5; i++)
        if(s[i] == hello[n])
            n++;
    if(n<5)
        puts("NO");
    else
        puts("YES");
    return 0;
}
