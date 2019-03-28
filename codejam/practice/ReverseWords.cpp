#include <cstdio>

#define MAXN 1032
#define MAXL 1032

int main()
{
    int t,n;
    char s[MAXN][MAXL];
    int i,tcase;
    char c;
    
    scanf("%d\n",&t);
    for(tcase=1;tcase<=t;tcase++)
    {
        n=0;
        i=0;
        while(1)
        {
            c = getchar();
            if(c == '\n')
            {
                s[n++][i++] = '\0';
                break;    
            }
            else if(c == ' ')
            {
                s[n++][i++] = '\0';
                i=0;
            }
            else
            {
                s[n][i++] = c;
            }
        }
        printf("Case #%d:", tcase);
        while(n--)
        {
            printf(" %s",s[n]);
        }
        puts("");
    }
    return 0;
}
