#include <cstdio>
int main()
{
    char s[100];
    int t=0;
    while(1)
    {
        t++;
        scanf("%s", s);
        if(s[0] == '*')
            break;
        printf("Case %d: ", t);
        if(s[0] == 'H')
            puts("Hajj-e-Akbar");
        else
            puts("Hajj-e-Asghar");
        
    }
    return 0;
}