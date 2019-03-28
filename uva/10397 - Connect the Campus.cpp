#include <cstdio>
#include <queue>
#include <vector>
#include <cmath>

#define M 1024

using namespace std;

typedef pair<double,double> point;
typedef pair<int,int> vertex;

int set[M];
int setSize;

double dist(point a, point b)
{
    return sqrt( pow(a.first-b.first, 2) + pow(a.second-b.second, 2) );
}

void initSet(int n)
{
    for(int i=1;i<=n;i++)
        set[i] = i;
    setSize = n;
}

int findSet(int i)
{
    if(i==set[i])
        return i;
    return (set[i] = findSet(set[i]));
}

bool isSameSet(int a, int b)
{
    return findSet(a) == findSet(b);
}

void unionSet(int a, int b)
{
    set[findSet(a)] = findSet(b);
    setSize--;
}

int main()
{
    int n,m,a,b;
    double cost;
    vector< point > pts(M);
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=1;i<=n;i++)
            scanf("%lf%lf",&pts[i].first,&pts[i].second);

        initSet(n);
        priority_queue< pair< double,vertex > > pq;

        for(int i=1;i<=n-1;i++)
            for(int j=i+1;j<=n;j++)
                if(!isSameSet(i,j))
                    pq.push( make_pair( -dist(pts[i],pts[j]), make_pair(i,j) ) );

        cost = 0.0;

        scanf("%d",&m);
        while(m--)
        {
            scanf("%d%d",&a,&b);
            
            if(!isSameSet(a,b))
                unionSet(a,b);
        }

        while(!pq.empty() && setSize>1)
        {
            pair< double, vertex > tmp = pq.top();
            pq.pop();
            if(!isSameSet(tmp.second.first, tmp.second.second))
            {
                unionSet(tmp.second.first, tmp.second.second);
                cost += (-tmp.first);
            }
        }
        printf("%.2lf\n",cost);
    }
    return 0;
}
