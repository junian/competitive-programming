#include <cstdio>
#include <algorithm>

#define MAX 20000

using namespace std;

typedef struct doll{
    int h,w;
};

bool cmp(doll a, doll b)
{
    return (a.h > b.h || (a.h==b.h && a.w > b.w));
}

bool exist(doll a, int m, doll *b)
{
    for(int i=0;i<m;i++)
        if(a.w<b[i].w && a.h<b[i].h)
        {
            b[i] = a;
            return true;
        }
    return false;
}

int main()
{
    doll b[MAX+32];
    doll d[MAX+32];
    int t,n,m,i,j;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%d%d",&d[i].w,&d[i].h);
        sort(d,d+n,cmp);
        m=0;
        for(i=0;i<n;i++)
            if(!exist(d[i],m,b))
                b[m++] = d[i];
        printf("%d\n",m);
    }
    return 0;
}
