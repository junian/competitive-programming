#include <cstdio>

#define REP(a,b,c) for(a=b;a<c;a++)
int main()
{
    int n,a,b,c,d,x;
    while(scanf("%d",&n)!=EOF)
    {
        x=0;
        REP(a,0,10)
            REP(b,0,10)
                REP(c,0,10)
                    REP(d,0,10)
                        if(a+b+c+d == n)
                            x++;
        printf("%d\n",x);
    }
    return 0;
}
