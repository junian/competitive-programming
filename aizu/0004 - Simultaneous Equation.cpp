#include <cstdio>

int main()
{
    int a,b,c,d,e,f;
    float res[2][3];
    float det;
    while(scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f)!=EOF)
    {
        det = a*e-b*d;
        res[0][0] = e/det;
        res[0][1] = -b/det;
        res[1][0] = -d/det;
        res[1][1] = a/det;
        res[0][2] = res[0][0]*c+res[0][1]*f;
        res[1][2] = res[1][0]*c+res[1][1]*f;
        printf("%.3f %.3f\n",res[0][2],res[1][2]);
    }
    return 0;
}
