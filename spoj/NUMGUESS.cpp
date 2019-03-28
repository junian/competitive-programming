#include <cstdio>

int main()
{
    int a, b, c;
    char s[256];
    scanf("%d %d",&a,&b);
    while(true)
    {
        if(a>b)
            break;
        c = (a+b)/2;
        printf("%d\n",c);
        fflush(stdout);
        scanf("%s",s);
        if(s[0] == 'W')
            break;
        else if(s[0] == 'H')
            b = c-1;
        else if(s[0] == 'L')
            a = c+1;
    }
    return 0;
}
