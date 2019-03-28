#include <cstdio>
#include <climits>
#include <algorithm>

using namespace std;

typedef struct turtle
{
    long long w;
    long long c;
};

bool comparison(turtle a, turtle b)
{
    return (a.c+a.w<b.c+b.w);
}

int main()
{
    turtle t[6000];
    long long best[6000],l;
    int i=0,j,k;
    while(scanf("%lld%lld",&t[i].w,&t[i].c)!=EOF)
        i++;
    sort(t,t+i,comparison);
    for(j=1;j<i;j++) best[j]=LONG_LONG_MAX;
    best[0]=0;
    l=0;
    for(j=0;j<i;j++)
    {
        for(k=l+1;k>0;k--)
            if(t[j].c>=best[k-1] && best[k-1]+t[j].w<best[k])
            {
                best[k]=best[k-1]+t[j].w;
                if(k>l) l=k;
            }
    }
    printf("%lld\n",l);
    return 0;
}
