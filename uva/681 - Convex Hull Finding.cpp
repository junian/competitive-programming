#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

typedef struct point{
    int x, y;
};

point pivot;

int turn(point p, point q, point r)
{
    int result = (r.x-q.x)*(p.y-q.y)-(r.y-q.y)*(p.x-q.x);
    if(result < 0) return -1;
    if(result > 0) return 1;
    return 0;
}

bool ccw(point p, point q, point r)
{
    return turn(p,q,r)>0;
}

int area2(point a, point b, point c)
{
    return a.x*b.y - a.y*b.x + b.x*c.y - b.y*c.x + c.x*a.y - c.y*a.x;
}

int dist2(point a, point b)
{
    int dx = a.x-b.x;
    int dy = a.y-b.y;
    return dx*dx + dy*dy;
}

bool angle_cmp(point a, point b)
{
    if(area2(pivot, a, b) == 0)
        return dist2(pivot,a)<dist2(pivot,b);
    int d1x = a.x-pivot.x, d1y = a.y-pivot.y;
    int d2x = b.x-pivot.x, d2y = b.y-pivot.y;
    return (atan2((double)d1y,(double)d1x) - atan2((double)d2y, (double)d2x))<0;
}

vector<point> grahamScan(vector<point> polygon)
{
    int i,po=0,n=polygon.size();
    for(i=1;i<n;i++)
        if(polygon[i].y < polygon[po].y ||
           (polygon[i].y == polygon[po].y && polygon[i].x < polygon[po].x))
            po = i;
    
    point temp = polygon[0];
    polygon[0] = polygon[po];
    polygon[po]=temp;

    pivot = polygon[0];

    sort(++polygon.begin(), polygon.end(), angle_cmp);
    //printf("aaaa\n");
        
    stack<point> s;
    point prev, now;
    s.push(polygon[n-1]);
    s.push(polygon[0]);
    i=1;
    while(i<n)
    {
        now = s.top();
        s.pop();
        prev = s.top();
        s.push(now);
        if(ccw(prev,now,polygon[i]))
        {
            s.push(polygon[i]);
            i++;
            //printf("aaa\n");
        }
        else
            s.pop();
    }
    //printf("aaa\n");
    vector<point> convexHull;
    while(!s.empty())
    {
        convexHull.push_back(s.top());
        s.pop();
    }
    //convexHull.pop_back();
    return convexHull;
}

bool cmp(point a, point b)
{
    if(a.y == b.y)
        return a.x<b.x;
    return a.y<b.y;
}
int main()
{
    vector<point> polygon;
    vector<point> convex;
    point pp;
    int t,n,i,tt;
    scanf("%d",&t);
    //tt=t;
    printf("%d\n",t);
    while(t--)
    {
        scanf("%d",&n);
        polygon.clear();
        for(i=0;i<n-1;i++)
        {
            scanf("%d%d",&pp.x,&pp.y);
            polygon.push_back(pp);
        }
        scanf("%d%d",&pp.x, &pp.y);
        convex = grahamScan(polygon);
        //printf("aaaaa");
        sort(convex.begin(), --convex.end(), angle_cmp);
        //sort(convex.begin(),convex.end(),cmp);
        printf("%d\n",convex.size());
        n = convex.size();
        for(i=0;i<n-1;i++)
            printf("%d %d\n",convex[i].x,convex[i].y);
        printf("%d %d\n",convex[0].x,convex[0].y);
        if(t>0)
        {
            scanf("%d",&i);
            printf("%d\n",i);
        }
    }

    return 0;
}
