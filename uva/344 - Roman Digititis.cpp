#include <cstdio>
int main()
{
    int i[10] = {0,1,2,3,1,0,1,2,3,1};
    int v[10] = {0,0,0,0,1,1,1,1,1,0};
    int x[10] = {0,1,2,3,1,0,1,2,3,1};
    int l[10] = {0,0,0,0,1,1,1,1,1,0};
    int c[10] = {0,1,2,3,1,0,1,2,3,1};

    int ii[101] = {0};
    int vv[101] = {0};
    int xx[101] = {0};
    int ll[101] = {0};
    int cc[101] = {0};

    int a,b,r;
    for(a=1;a<=99;a++)
    {
        b=a;
        r=b%10;
        b=b/10;
        ii[a] = i[r]+ii[a-1];
        vv[a] = v[r]+vv[a-1];
        xx[a] = xx[a-1] + (r==9?+1:0);
        r=b%10;
        b=b/10;
        xx[a] += x[r];
        ll[a] = l[r]+ll[a-1];
        cc[a] = cc[a-1] + (r==9?1:0);
    }
    ii[100]=ii[99];
    vv[100]=vv[99];
    xx[100]=xx[99];
    ll[100]=ll[99];
    cc[100]=cc[99]+1;
    while(1)
    {
        scanf("%d",&a);
        if(a==0) break;
        printf("%d: %d i, %d v, %d x, %d l, %d c\n",a,ii[a],vv[a],xx[a],ll[a],cc[a]);
    }
    return 0;
}
