#include <cstdio>

int main()
{
    int t;
    double a,b,c,d,r,m,n,o,aa,bb,cc,dd;
    const double x=52.50,y1=3.660,y2=-3.660;
    bool goal;
    scanf("%d",&t);
    while(t--)
    {
        goal=false;
        scanf("%lf%lf",&c,&d);
        scanf("%lf%lf%lf",&a,&b,&r);

        m = (y1-d)/(x-c);
        n = d - m*c;
        o = n - b;
        aa = m*m + 1.0;
        bb = 2.0*(o*m - a);
        cc = a*a + o*o - r*r;
        dd = bb*bb - 4.0*aa*cc;
        if(dd<0.0) goal=true;

        m = (y2-d)/(x-c);
        n = d - m*c;
        o = n - b;
        aa = m*m + 1.0;
        bb = 2.0*(o*m - a);
        cc = a*a + o*o - r*r;
        dd = bb*bb - 4.0*aa*cc;
        if(dd<0.0) goal=true;

        if(goal)
            puts("Goal!");
        else
            puts("No goal...");
    }
    return 0;
}
