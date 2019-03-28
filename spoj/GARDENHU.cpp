#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stack>

#define MAX 10000

using namespace std;

typedef struct point
{
    int x, y;
};

point pivot;
point pts[MAX];
int N;

void swap(point *a, point *b)
{
    point tmp = *a;
    *a = *b;
    *b = tmp;
}
// = 0 colinear
// > 0 counter clockwis
// < 0 clockwise
int ccw(point p1, point p2, point p3)
{
    return (p2.x - p1.x)*(p3.y - p1.y) - (p2.y - p1.y)*(p3.x - p1.x);
}

double dist(point a, point b)
{
    int x = a.x-b.x;
    int y = a.y-b.y;

    return sqrt((double)x*x+y*y);
}

bool angle_cmp(point a, point b)
{
//    if(ccw(pivot,a,b) == 0)
//        return dist(pivot,a)<dist(pivot,b);

    int dx1 = a.x-pivot.x;
    int dy1 = a.y-pivot.y;

    int dx2 = b.x-pivot.x;
    int dy2 = b.y-pivot.y;

    return atan2( (double)dy1, (double)dx1 ) < atan2( (double)dy2, (double)dx2 );
}

int main()
{
    scanf("%d",&N);
    scanf("%d%d",&pts[0].x, &pts[0].y);
    int min = 0;

    for(int i=1;i<N;i++)
    {
        scanf("%d%d",&pts[i].x,&pts[i].y);
        if(pts[i].y < pts[min].y || (pts[i].y == pts[min].y && pts[i].x<pts[min].x))
            min = i;
    }
    pivot = pts[min];

    swap(&pts[0],&pts[min]);

    sort(pts+1,pts+N,angle_cmp);

    stack<point> res;
    res.push(pts[0]);
    res.push(pts[1]);
    res.push(pts[2]);

    point a,b;

    for(int i=3;i<N;i++)
    {
        a = res.top();
        res.pop();
        b = res.top();
        res.pop();
        while(ccw(b,a,pts[i])<=0)
        {
            a = b;
            b = res.top();
            res.pop();
        }
        res.push(b);
        res.push(a);
        res.push(pts[i]);
    }

    point start = pivot;

    double le = 0.0;

    while(!res.empty())
    {
        point tmp = res.top();
        res.pop();
        le += dist(tmp, start);
        start = tmp;
    }

    printf("%d\n",(int) le);
    return 0;
}
