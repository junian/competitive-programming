#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

#define MAX 2004

int main()
{
    vector<int> adjList[MAX];
    int color[MAX];
    int n,m,a,b,t;
    bool isBipartite;
    scanf("%d",&t);
    for(int c=1;c<=t;c++)
    {
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)
            adjList[i].clear(),color[i]=-1;
        isBipartite = true;

        while(m--)
        {
            scanf("%d%d",&a,&b);
            adjList[a].push_back(b);
            adjList[b].push_back(a);
        }
        for(int i=1;isBipartite && i<=n;i++)
        {
            if(color[i] == -1)
            {
                queue<int> q;
                q.push(i);
                color[i] = 0;
                while(isBipartite && !q.empty())
                {
                    a = q.front();
                    q.pop();
                    for(int i=0;isBipartite && i<adjList[a].size();i++)
                    {
                        if(color[ adjList[a][i] ] == -1)
                        {
                            color[ adjList[a][i] ] = !color[a];
                            q.push( adjList[a][i] );
                        }
                        else if(color[ adjList[a][i] ] == color[a])
                            isBipartite = false;
                    }
                }
            }
        }
        printf("Scenario #%d:\n",c);
        if(!isBipartite)
            puts("Suspicious bugs found!");
        else
            puts("No suspicious bugs found!");
    }
    return 0;
}
