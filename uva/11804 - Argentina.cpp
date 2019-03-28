#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
typedef struct player
{
    char n[32];
    int a;
    int d;
};
bool cmp1(player a, player b)
{
    if(a.a==b.a)
    {
        if(a.d==b.d)
            return strcmp(a.n,b.n)<0;
        return a.d<b.d;
    }
    return a.a>b.a;
}

bool cmp2(player a, player b)
{
    return strcmp(a.n,b.n)<0;
}

int main()
{
    int t,i,c;
    player p[11];
    scanf("%d",&t);
    for(c=1;c<=t;c++)
    {
        for(i=0;i<10;i++)
            scanf("%s%d%d",p[i].n,&p[i].a,&p[i].d);
        sort(p,p+10,cmp1);
        sort(p,p+5,cmp2);
        sort(p+5,p+10,cmp2);
        printf("Case %d:\n",c);
        printf("(%s, %s, %s, %s, %s)\n",p[0].n,p[1].n,p[2].n,p[3].n,p[4].n);
        printf("(%s, %s, %s, %s, %s)\n",p[5].n,p[6].n,p[7].n,p[8].n,p[9].n);
    }
    return 0;
}
