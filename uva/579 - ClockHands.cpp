#include <cstdio>
int main()
{
    int i,j;
    double a,b;
    char x[10];
    while(1)
    {
        scanf("%s",x);
        a=0.0;b=0.0;
        for(i=0;x[i]!=':';i++)
            a=a*10.0+(x[i]-'0');
        i++;
        for(i=i;x[i]!='\0';i++)
            b=b*10.0+(x[i]-'0');
        if(a==0.0 && b==0.0)
            break;
        a=0.5*(60.0*a-11.0*b);
        a=a<0.0?-a:a;
        a=a>180.0?360.0-a:a;
        printf("%.3lf\n",a);
    }
    return 0;
}
