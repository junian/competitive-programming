#include <cstdio>
#include <queue>

using namespace std;

typedef pair<int,int> edge;

#define M 1000001

int set[M];
int size;

void initSet(int n)
{
    size = n;
    for(int i=1;i<=n;i++)
        set[i] = i;
}

int findSet(int i)
{
    if(set[i] == i)
        return i;
    return set[i] = findSet(set[i]);
}

bool isSameSet(int a, int b)
{
    return findSet(a) == findSet(b);
}

void unionSet(int a, int b)
{
    if(!isSameSet(a,b))
    {
        set[findSet(a)] = findSet(b);
        size--;
    }
}

int main()
{
    int n,m,a,b,c;
    bool t=false;
    long long oricost, newcost;
    while(scanf("%d",&n)!=EOF)
    {
        if(t)
            puts("");
        oricost = newcost = 0;
        initSet(n);
        priority_queue< pair<int, edge > > pq;
        for(int i=0;i<n-1;i++)
        {
            scanf("%d%d%d",&a,&b,&c);
            pq.push( make_pair(-c, make_pair(a,b)) );
            oricost += c;
        }
        scanf("%d",&m);
        while(m--)
        {
            scanf("%d%d%d",&a,&b,&c);
            pq.push( make_pair(-c, make_pair(a,b)) );
        }
        scanf("%d",&m);
        while(m--)
        {
            scanf("%d%d%d",&a,&b,&c);
            pq.push( make_pair(-c, make_pair(a,b)) );
        }
        while(!pq.empty() && size>1)
        {
            pair< int, edge > tmp = pq.top();
            pq.pop();
            if(!isSameSet( tmp.second.first, tmp.second.second ))
            {
                newcost += (-tmp.first);
                unionSet(tmp.second.first, tmp.second.second);
            }
        }
        printf("%lld\n%lld\n",oricost,newcost);
        t=true;
    }
    return 0;
}
