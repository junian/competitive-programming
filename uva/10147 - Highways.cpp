#include <cstdio>
#include <queue>

using namespace std;

#define MAX 751

typedef pair<int,int> point;

int set[MAX];
int setSize;

int pow2(int a)
{
    return a*a;
}

int dist(point a, point b)
{
    return pow2(a.first-b.first) + pow2(a.second-b.second);
}

void initSet(int n)
{
    setSize = n;
    for(int i=1;i<=n;i++)
        set[i] = i;
}

int findSet(int i)
{
    return set[i] = (set[i] == i ? i : findSet(set[i]));
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
        setSize--;
    }
}
int main()
{
    int t,n,m,a,b;
    scanf("%d",&t);
    pair<int, int> city[MAX];
    while(t--)
    {
        scanf("%d",&n);
        initSet(n);
        for(int i=1;i<=n;i++)
            scanf("%d%d",&city[i].first, &city[i].second);
        scanf("%d",&m);
        while(m--)
        {
            scanf("%d%d",&a,&b);
            unionSet(a,b);
        }
        if(setSize == 1)
            puts("No new highways need");
        else
        {
            priority_queue< pair<int, point> > pq;
            for(int i=1;i<=n-1;i++)
                for(int j=i+1;j<=n;j++)
                    if(!isSameSet(i,j))
                        pq.push( make_pair( -dist(city[i], city[j]), make_pair(i,j) ) );
            while(!pq.empty() && setSize>1)
            {
                pair< int, point > tmp = pq.top();
                pq.pop();
                if(!isSameSet( tmp.second.first, tmp.second.second ))
                {
                    unionSet( tmp.second.first, tmp.second.second );
                    printf("%d %d\n",tmp.second.first, tmp.second.second);
                }
            }

        }
        if(t)
            puts("");
    }
    return 0;
}
