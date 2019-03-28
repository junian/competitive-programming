#include <stdio.h>

int main()
{
    int t, n, i, c, j;
    char sp[81];
    char cr[81];

    scanf("%d", &t);
    i=1;
    while(t>0)
    {
        t--;
        c=0;
        scanf("%d %s", &n, sp);
        n--;
        for(j=0; j<n; j++)
        {
            cr[c] = sp[j];
            c++;
        }
        for(j=n+1; sp[j]!='\0'; j++)
        {
            cr[c] = sp[j];
            c++;
        }
        cr[c] = '\0';
        printf("%d %s\n", i, cr);
        i++;
    }
    return 0;
}
