#include <cstdio>

int main()
{
    unsigned int z, i, m, l, nextRan, last;
    int c = 0;
    int r = 0;

    while(true)
    {
        c++;
        scanf("%d %d %d %d", &z, &i, &m, &l);
        if(z==0 && i==0 && m==0 && l==0)
            break;
        r = 0;
        last = l;
        while(true)
        {
            r++;
            nextRan = ((z*last)+i)%m;
            printf("%d %d %d %d %d %d\n", z,i,m,last, nextRan, r);
            if(r==500) while(true);
            if(nextRan == l)
                break;
            last = nextRan;
        }
        printf("Case %d: %d\n", c, r);
    }

    return 0;
}
