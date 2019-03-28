#include <cstdio>

int gcd(int a, int b)
{
    if(b==0)
        return a;
    return gcd(b, a % b);
}

int main()
{
    int t, n, i, c;
    int r[100];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%d",&r[i]);
        c = r[0];
        for(i=1;i<n;i++)
            c = gcd(c,r[i]);
        printf("%d",r[0]/c);
        for(i=1;i<n;i++)
            printf(" %d",r[i]/c);
        puts("");
    }
    return 0;
}
