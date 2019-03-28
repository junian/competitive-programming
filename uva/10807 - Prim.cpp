#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

typedef pair<int,int> edge;

#define M 32

int sets[2][M];
int setSize[2];

void initSet(int* set, int n)
{
    for(int i=1;i<=n;i++)
        set[i] = i;
}

int findSet(int* set, int i)
{
    if(set[i] == i)
        return i;
    return set[i] = findSet(set, set[i]);
}

bool isSameSet(int* set, int a, int b)
{
    return findSet(set, a) == findSet(set, b);
}

void unionSet(int* set, int a, int b)
{
    if(!isSameSet(set, a,b))
    {
        set[findSet(set, a)] = findSet(set, b);
    }
}

int main()
{
    int n,m,x,y,z,cost;
    while(scanf("%d",&n),n)
    {
        scanf("%d",&m);
        initSet(sets[0],n);
        initSet(sets[1],n);
        setSize[0] = setSize[1] = n;
        cost = 0;
        vector< pair<int, edge> > pq;
        while(m--)
        {
            scanf("%d%d%d",&x,&y,&z);
            pq.push_back( make_pair(-z, make_pair(x,y)) );
        }
        while(!pq.empty())
        {
            pair<int, edge> tmp = pq.top();
            pq.pop();
            if(!isSameSet(sets[0], tmp.second.first, tmp.second.second ))
            {
                setSize[0]--;
                unionSet(sets[0], tmp.second.first, tmp.second.second );
                cost += (-tmp.first);
            }
            else if(!isSameSet(sets[1], tmp.second.first, tmp.second.second ))
            {
                setSize[1]--;
                unionSet(sets[1], tmp.second.first, tmp.second.second );
                cost += (-tmp.first);
            }
        }
        if(setSize[0] == 1 && setSize[1] == 1)
            printf("%d\n",cost);
        else
            puts("No way!");
    }
    return 0;
}
