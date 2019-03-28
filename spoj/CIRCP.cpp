#include <cstdio>

typedef struct circle
{
    int a,b,r;
};

int pow2(int a)
{
    return a*a;
}
int main()
{
    circle c[501];
    int m,n,t,i,j,l,x,y;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&m,&n);
        for(i=0;i<m;i++)
        {
            scanf("%d%d%d",&c[i].a,&c[i].b,&l);
            c[i].r = l*l;
        }
        for(i=0;i<n;i++)
        {
            l=0;
            scanf("%d%d",&x,&y);
            for(j=0;j<m;j++)
            {
                if(pow2(x-c[j].a)+pow2(y-c[j].b)<=c[j].r)
                    l++;
            }
            printf("%d\n",l);
        }
    }
    return 0;
}
