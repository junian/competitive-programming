#include<cstdio>
#include<cmath>
int main()
{
    int t;
//    double ab,ac,ad,bc,bd,cd,l1,l2,l3,t1,t2,h,s,v;
    double u,v,w,W,V,U,x;
    scanf("%d", &t);
    while(t-->0)
    {
        scanf("%lf%lf%lf%lf%lf%lf",&u,&v,&w,&W,&V,&U);
//        scanf("%lf%lf%lf%lf%lf%lf",&ab,&ac,&ad,&bc,&bd,&cd);
//        s=(ab+bc+ac)/2.0;
//        l1=sqrt(s*(s-ab)*(s-bc)*(s-ac));
//        t1=2.0*l1/ab;
//        s=(ab+bd+ad)/2.0;
//        l2=sqrt(s*(s-ab)*(s-bd)*(s-ad));
//        t2=2.0*l2/ab;
//        s=(t1+t2+cd)/2.0;
//        l3=sqrt(s*(s-t1)*(s-t2)*(s-cd));
//        h=2.0*l3/t1;
//        v=(l1*h)/3.0;
        x=sqrt(4*u*u*v*v*w*w- u*u*pow((v*v+w*w - U*U),2) - v*v*pow((w*w+u*u - V*V),2) - w*w*pow((u*u + v*v - W*W),2) + (v*v +w*w - U*U)*(w*w+u*u- V*V)*(u*u+v*v - W*W))/12;
        printf("%.4lf\n", x);
    }
    return 0;
}
