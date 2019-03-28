#include <cstdio>

#define MAX 50000
#define CC  (n+i-1)%n

typedef struct point
{
    double x,y;
};

point points[MAX+32];
double xi[MAX+32],yi[MAX+32];

int main()
{
    int n,q,i,a,b;
    double lall,l1, l2, xx, yy;
    scanf("%d%d",&n,&q);
    for(i=0;i<n;i++)
        scanf("%lf%lf",&points[i].x,&points[i].y);
    lall = 0.0;
    xx = 0.0;
    yy = 0.0;
    for(i=n-1;i!=0;i=CC)
    {
        xx += xi[i] = points[i].x*points[CC].y;
        yy += yi[i] = points[i].y*points[CC].x;
    }
    xx += xi[0] = points[0].x*points[n-1].y;
    yy += yi[0] = points[0].y*points[n-1].x;
    lall = 0.5*(xx - yy);
    while(q--)
    {
        scanf("%d%d",&a,&b);
        l1 = l2 = 0.0;
        xx = yy = 0.0;
        if((((b+n-a)%n) < (a+n-b)%n))
        {
            for(i=b;i!=a;i=CC)
            {
                xx += xi[i];//points[i].x*points[CC].y;
                yy += yi[i];//points[i].y*points[CC].x;
            }
            xx += points[a].x*points[b].y;
            yy += points[a].y*points[b].x;
        }
        else
        {
            for(i=a;i!=b;i=CC)
            {
                xx += xi[i];//points[i].x*points[CC].y;
                yy += yi[i];//points[i].y*points[CC].x;
            }
            xx += points[b].x*points[a].y;
            yy += points[b].y*points[a].x;
        }
        l1 = 0.5*(xx - yy);
        l2 = lall - l1;
//        xx = yy = 0.0;
//        for(i=b;i!=a;i=CC)
//        {
//            xx += points[i].x*points[CC].y;
//            yy += points[i].y*points[CC].x;
//        }
//        xx += points[a].x*points[b].y;
//        yy += points[a].y*points[b].x;
//        l2 = 0.5*(xx - yy);
        if(l1<l2)
            printf("%0.1lf\n",l1);
        else
            printf("%0.1lf\n",l2);
    }
    return 0;
}
