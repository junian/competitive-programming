#include <cstdio>
#define max(a,b) (a>b)?a:b

int main()
{
    double a,b,c,d;
    double s1,s2,s3,s4,mx;
    int n;
    scanf("%lf%lf",&a,&b);
    scanf("%lf%lf",&c,&d);
    s1 = (a/c)+(b/d);
    mx=s1;
    n=0;

    s2 = (c/d)+(a/b);
    if(mx<s2)
    {
        mx=s2;
        n=1;
    }
    s3 = (d/b)+(c/a);
    if(mx<s3)
    {
        mx=s3;
        n=2;
    }
    s4 = (b/a)+(d/c);
    if(mx<s4)
    {
        mx=s4;
        n=3;
    }
    printf("%d\n",n);
    return 0;
}
