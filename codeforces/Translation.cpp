#include <cstdio>
#include <cstring>

void rev(char *a, char*b)
{
    char c;
    while(a<b)
    {
        c = *a;
        *a = *b;
        *b=c;
        a++;
        b--;
    }
}

int main()
{
    char a[128],b[128];
    int n;
    gets(a);
    gets(b);
    n = strlen(b);
    rev(&b[0],&b[n-1]);
    if(strcmp(a,b)==0)
        puts("YES");
    else
        puts("NO");
    return 0;
}
