#include <stdio.h>

int main()
{
    int squares[101];
    int i, n;
    squares[1] = 1;
    for(i=2; i<=100; i++)
    {
        squares[i] = squares[i-1] + i*i;
    }
    while(1)
    {
        scanf("%d", &n);
        if(n==0) break;
        printf("%d\n", squares[n]);
    }
    return 0;
}
