#include <cstdio>
#include <cmath>

using namespace std;

typedef struct point
{
    double x,y;
};

point a,b;
double ra,rb;

double circle(point p1, point p2, double r1, double r2)
{
    double cx0 = p1.x;
    double cx1 = p2.x;
    double cy0 = p1.y;
    double cy1 = p2.y;
    
    double dx = cx0 - cx1;
    double dy = cy0 - cy1;
    double distSq = dx * dx + dy * dy;
    double dist = sqrt(distSq);

    if (dist > r1 + r2)
    {
        return 0.0;
    }
    if (dist < abs(r1 - r2))
    {
        return 0.0;
    }
    if ((dist == 0.0) && (r1 == r2))
    {
        return 0.0;
    }

    double a = (r1 * r1 - r2 * r2 + distSq) / (2.0 * dist);
    double h = sqrt(r1 * r1 - a * a);

    double cx2 = cx0 + a * (cx1 - cx0) / dist;
    double cy2 = cy0 + a * (cy1 - cy0) / dist;

    double sx1 = (cx2 + h * (cy1 - cy0) / dist);
    double sy1 = (cy2 - h * (cx1 - cx0) / dist);

    double sx2 = (cx2 - h * (cy1 - cy0) / dist);
    double sy2 = (cy2 + h * (cx1 - cx0) / dist);
    
    double dxx = sx2 - sx1;
    double dyy = sy2 - sy1;
    return sqrt(dxx*dxx+dyy*dyy);
}

int main()
{
    int t;
    scanf("%d", &t);
    for(int tc = 1;tc<=t;tc++)
    {
        scanf("%lf %lf %lf %lf %lf %lf", &a.x, &a.y, &b.x, &b.y, &ra, &rb);
        //printf("%lf %lf %lf %lf %lf %lf\n", a.x, a.y, b.x, b.y, ra, rb);
        rb = sqrt(2.0*rb*rb)/2.0;
        //printf("%lf %lf %lf %lf %lf %lf\n", a.x, a.y, b.x, b.y, ra, rb);
        double res = circle(a,b,ra,rb);
        printf("%d. ", tc);
        if(res==0.0)
            puts("No problem");
        else
            printf("%.3lf\n", res);
    }
    
    return 0;
}
