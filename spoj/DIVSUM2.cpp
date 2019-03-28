#include <cstdio>

int main()
{
    long long t, n, tot, i, h;
    scanf("%d", &t);
    while(t>0)
    {
        t--;
        scanf("%d", &n);
        if(n==1)
            tot = 0;
        else
            tot=1;
        for(i=2; i*i < n; i++)
        {
            if(n%i == 0)
            {
                tot += i;
                tot += n/i;
            }
        }
        if(i*i == n)
            tot += i;
        printf("%d\n", tot);
    }
    return 0;
}

