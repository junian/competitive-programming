#include <cstdio>
#include <queue>
#include <cmath>
using namespace std;

typedef pair<float,float> point;
typedef pair<int,int> vertex;

int set[128];
int tot;

float dist(point a, point b)
{
    return sqrt(pow(a.first-b.first,2)+pow(a.second-b.second,2));
}

void initSet(int size)
{
    for(int i=0;i<size;i++)
        set[i] = i;
    tot=size;
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
    tot--;
}

int main()
{
    int t,n;
    vector< point > points(128);
    float cost;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        cost = 0.0f;
        initSet(n);
        for(int i=0;i<n;i++)
            scanf("%f%f",&points[i].first,&points[i].second);
        priority_queue< pair<float,vertex> > pq;
        for(int i=0;i<n-1;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                pq.push(make_pair(-dist(points[i],points[j]), make_pair(i,j)));
            }
        }
        while(tot>1)
        {
            pair<float,vertex> temp = pq.top();
            pq.pop();
            if(!isSameSet(temp.second.first,temp.second.second))
            {
                unionSet(temp.second.first,temp.second.second);
                cost += (-temp.first);
            }
        }
        printf("%.2f\n",cost);
        if(t)
            puts("");
    }
    return 0;
}
