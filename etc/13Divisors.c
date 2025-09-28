#include <stdio.h>

int main()
{
    int t, n, i;
    scanf("%d", &t);
    while(t>0)
    {
        t--;
        scanf("%d", &n);
        printf("1");
        for(i=2; i<=n/2; i++)
        {
            if(n%i == 0)
                printf(" %d", i);
        }
        printf("\n");
    }
    return 0;
}
