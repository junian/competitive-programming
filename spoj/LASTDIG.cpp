#include <stdio.h>

int main()
{
    int i, j, t, a, b;
    scanf("%d", &t);
    while(t>0)
    {
        t--;
        scanf("%d %d", &a, &b);
        if(b==0)
            printf("1\n");
        else
        {
            a = a % 10;
            b = b % 4;
            b = b==0?4:b;
            j=1;
            for(i=0; i<b; i++)
                j *= a;
            j = j % 10;
            printf("%d\n", j);
        }
    }
    return 0;
}
