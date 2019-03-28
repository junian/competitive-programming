#include <stdio.h>

int main()
{
    int t, n, i, j;
    scanf("%d", &t);
    while(t>0)
    {
        t--;
        scanf("%d", &n);
        for(i=0; i<n; i++)
            scanf("%d", &j);
        printf("ALICE\n");
    }
    return 0;
}
