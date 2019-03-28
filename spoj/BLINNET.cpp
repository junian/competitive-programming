#include <cstdio>
#include <queue>
//#include <map>
//#include <string>

using namespace std;

#define M 10024

typedef pair<int,int> point;

int set[M];
int size;

void initSet(int n)
{
    for(int i=1;i<=n;i++)
        set[i] = i;
    size = n;
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
    set[findSet(a)] = findSet(b);
    size--;
}

int main()
{
    int n,m,a,b,c,t,d;
    char city[32];
    long long mincost;
    scanf("%d",&t);
//    map<string, int> cityID;
    while(t--)
    {
        scanf("%d",&n);
        initSet(n);
        mincost=0;
        priority_queue< pair<int, point> > pq;
        for(int i=1;i<=n;i++)
        {
            scanf("%s",city);
            scanf("%d",&m);
            while(m--)
            {
                scanf("%d%d",&b,&c);
                pq.push( make_pair( -c, make_pair( i,b ) ) );
            }
        }

//        cityID.clear();

        while(size>1 && !pq.empty())
        {
            pair< int, point > tmp = pq.top();
            pq.pop();
            if(!isSameSet( tmp.second.second, tmp.second.first ))
            {
                unionSet( tmp.second.second, tmp.second.first );
                mincost += (-tmp.first);
            }
        }
        printf("%lld\n",mincost);
    }
    return 0;
}
