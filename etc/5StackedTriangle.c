#include <stdio.h>
#include <string.h>

int main()
{
    char s[256][256];
    int i, j;
    for(i=0; i<99; i++)
    {
        strcpy(s[i], "*");
        for(j=1; j<i*2+1; j++)
            strcat(s[i], "*");
    }

    int t, n, a;
    scanf("%d", &t);
    while(t>0)
    {
        t--;
        scanf("%d", &n);
        for(i=1; i<=n; i++)
        {
            for(j=0; j<=i; j++)
            {
                for(a=0; a<n-j; a++) printf(" ");
                printf("%s\n", s[j]);
            }
        }
    }
    return 0;
}
