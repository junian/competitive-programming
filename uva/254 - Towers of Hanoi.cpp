#include <stdio.h>

void hanoi(int n, int*a, int *b, int* c, unsigned long long* m)
{
    if(*m <= 0) return;
    if(n<=0) return;
    hanoi(n-1, a, c, b, m);
    if(*m <= 0) return;
    *a = *a-1;
    *c = *c+1;
    *m = *m - 1;
    if(*m <= 0) return;
    hanoi(n-1,b,a,c,m);
}

int main()
{
    unsigned long long m=0;
    int a = 0, b = 0, c = 0, n = 0;
    while(true)
    {
        scanf("%d %d", &n, &m);
        if(n==0 && m==0) return 0;
        a = n;
        b = c = 0;
        hanoi(n, &a, &b, &c, &m);
        printf("%d %d %d\n", a, b, c);
    }

    return 0;
}
