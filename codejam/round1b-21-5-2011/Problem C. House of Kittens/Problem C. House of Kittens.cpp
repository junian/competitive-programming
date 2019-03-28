#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

#define MAX 2048

int minimum;
vector< int > edgeList[MAX];
bool visited[MAX];
int vis[MAX][MAX];

void dfs(int v, int depth)
{
    if(visited[v])
    {
        if(depth < minimum)
            minimum = depth;
    }
    else
        visited[v] = true;
    
    for(int i=0;i<edgeList[v].size();i++)
    {
        
    }    
}

int main()
{
    int t;
    int n,m;
    scanf("%d",&t);
    for(int c=1;c<=t;c++)
    {
        
        int fromv[MAX];
        int tov[MAX];

        minimum = MAX+9999;    
        scanf("%d%d",&n,&m);
        
        for(int i=0;i<n;i++)
        {
            visited[i] = false;
            edgeList[i].clear();
            edgeList[i].push_back( (i+1)%n );
            edgeList[(i+1)%n].push_back( i );
            for(int j=0;j<n;j++)
                vis[i][j] = 0;
        }
        for(int i=0;i<m;i++)
            scanf("%d",&fromv[i]):
        for(int i=0;i<m;i++)
        {
            scanf("%d",&tov[i]):
            edgeList[ fromv[i] ].push_back( tov[i] );
            edgeList[ tov[i] ].push_back( fromv[i] );
        }

        printf("Case #%d: ",c);
    }
    return 0;
}
