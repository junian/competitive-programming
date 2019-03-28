#include <stdio.h>
#include <math.h>


double length(double x1, double y1, double x2, double y2)
{
    return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}

int main()
{
    int t;
    double eps = 1e-6;
    scanf("%d", &t);
    while(t--)
    {
        double a,b,c,h,s1,s2;
        scanf("%lf %lf %lf %lf %lf %lf", &a, &b, &c, &h, &s1, &s2);
        
        double lo = 0.0;
        double hi = c;
        
        //double min = length(0.0, a+b+h, c/2.0, h)*s1 + length(c/2.0, h, c, 0.0)*s2;
        
        
        int iter=0;
        while(lo - hi < eps)
        {
            iter++;
            double mid = (lo+hi)/2.0 - eps;
            double midl = mid - (mid-lo)/1024.0 - eps;
            double midr = mid + (hi-mid)/1024.0 - eps;
            
            double cost1 = length(0.0, a+b+h, midl, h)*s1 + length(midl, h, c, 0.0)*s2 - eps;
            
            double cost2 = length(0.0, a+b+h, mid, h)*s1 + length(mid, h, c, 0.0)*s2 - eps;        
            
            double cost3 = length(0.0, a+b+h, midr, h)*s1 + length(midr, h, c, 0.0)*s2 - eps;
            
//            printf("%lf %lf %lf\n", cost1, cost2, cost3);
            
            if(cost1-cost2<eps && cost1-cost3<eps)
            {
                //lo = (mid+lo)/2.0;
                hi = mid;
            }
            else if(cost2-cost1<eps && cost2-cost3<eps)
            {
                lo = midl;
                hi = midr;
            }
            else
            {
                lo = mid;   
                //hi = (mid+hi)/2.0;
            }
        }
        printf("%d\n", iter);
        double min = length(0.0, a+b+h, lo, h)*s1 + length(lo, h, c, 0.0)*s2;
        printf("%.2lf\n", min);
    }
    
    return 0;
}
