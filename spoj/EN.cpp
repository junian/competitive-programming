#include <cstdio>
#include <set>
#include <vector>
#include <cstring>
#include <algorithm>

#define MAX 100

using namespace std;

int n;
int dfsCounter;

vector<int> adjList[MAX];

int depth[MAX];
int children;
int dfsnum[MAX];
int lowpoint[MAX];

//vector< pair<int, int> > bridges;
set< int > arcPoints;

char c;

int readInt()
{
    int a=0;
    while(c=getchar())
    {
        if(c == '\n' || c == ' ')
            break;
        a = a*10 + (c-'0');
    }
    return a;
}

void init()
{
    dfsCounter = 0;
    memset(depth,-1,sizeof(depth));
//    memset(children,0,sizeof(children));
    memset(dfsnum,-1,sizeof(dfsnum));
    memset(lowpoint,-1,sizeof(lowpoint));
    for(int i=1;i<=n;i++)
        adjList[i].clear();
//    bridges.clear();
    arcPoints.clear();
//    while(!edges.empty())
//        edges.pop();
    children = 0;
}

void dfsArcAndBridges(int v, int d)
{
    dfsnum[v] = dfsCounter++;
    lowpoint[v] = dfsnum[v];
    depth[v] = d;

    for(int i=0;i<adjList[v].size(); i++)
    {
        int child = adjList[v][i];
        if(depth[ child ] == -1)
        {
            if(depth[v] == 0)
                children++;

            dfsArcAndBridges(child, d+1);

            lowpoint[v] = min(lowpoint[v], lowpoint[child] );

            if(dfsnum[v] == 0)
            {
                if(children > 1)
                    arcPoints.insert(v);
            }
            else if(lowpoint[child] >= dfsnum[v])
            {
                arcPoints.insert(v);
//                bridges.push_back(make_pair(v,child));
            }
        }
        else if(depth[child] < depth[v]-1)
        {
            lowpoint[v] = min(lowpoint[v], dfsnum[child]);
        }
    }
}

int main()
{
    int a,b;
    while(true)
    {
        n=readInt();
        if(n==0)
            break;
        init();
        while(true)
        {
            a=readInt();
            if(a == 0)
                break;
            while(true)
            {
                b = readInt();
                adjList[a].push_back(b);
                adjList[b].push_back(a);
                if(c=='\n')
                    break;
            }
        }
        dfsArcAndBridges(1,0);
//        for(int i=0;i<arcPoints.size();i++)
//            printf("a: %d\n",arcPoints[i]);
        printf("%d\n",arcPoints.size());
    }
    return 0;
}
