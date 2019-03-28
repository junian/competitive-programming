#include <stdio.h>

int main()
{
    int five[12] = {5, 25, 125, 625, 3125, 15625, 78125, 390625, 1953125, 9765625, 48828125, 244140625};
    int t, n, i;
    int tot, sub;
    scanf("%d", &t);
    while(t>0)
    {
        t--;
        scanf("%d", &n);
        tot=0;
        for(i=0; i<12; i++)
        {
            sub = n/five[i];
            if(sub == 0) break;
            tot += sub;
        }
        printf("%d\n", tot);
    }

    return 0;
}
