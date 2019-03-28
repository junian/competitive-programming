#include <cstdio>

int main()
{
    double x[4],y[4];
    double l,xr,yr;
    int i,n;
    scanf("%d",&n);
    printf("INTERSECTING LINES OUTPUT\n");
    while(n--)
    {
        for(i=0;i<4;i++)
            scanf("%lf%lf",&x[i],&y[i]);
        l = (x[0]-x[1])*(y[2]-y[3])-(y[0]-y[1])*(x[2]-x[3]);
//        printf("(x0-x1)(y2-y3)-(y0-y1)(x2-x3) = %lf\n",l);

        xr = (x[0]*y[1]-y[0]*x[1])*(x[2]-x[3])-(x[0]-x[1])*(x[2]*y[3]-y[2]*x[3]);
//        printf("(x0y1-y0x1)(x2-x3)-(x0-x1)(x2y3-y2x3)=%lf\n",xr);

        yr = (x[0]*y[1]-y[0]*x[1])*(y[2]-y[3])-(y[0]-y[1])*(x[2]*y[3]-y[2]*x[3]);
//        printf("(x0y1-y0x1)(y2-y3)-(y0-y1)(x2y3-y2x3)=%lf\n",yr);
        if(l==0.0)
        {
            if(xr==0.0 && yr==0.0)
                printf("LINE\n");
            else
                printf("NONE\n");
        }
        else
            printf("POINT %.2lf %.2lf\n",xr/l,yr/l);
    }
    printf("END OF OUTPUT\n");
    return 0;
}
