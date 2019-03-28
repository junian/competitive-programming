#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX 204

int main()
{
    vector<int> adjList[MAX];
    int color[MAX];
    int n,m,a,b,t,tot;
    bool isBipartite;
    scanf("%d",&t);
    for(int c=1;c<=t;c++)
    {
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++)
            adjList[i].clear(),color[i]=-1;
        isBipartite = true;

        while(m--)
        {
            scanf("%d%d",&a,&b);
            adjList[a].push_back(b);
            adjList[b].push_back(a);
        }

        tot=0;

        for(int i=0;isBipartite && i<n;i++)
        {
            if(adjList[i].size() == 0)
                tot++;
            else if(color[i] == -1)
            {
                queue<int> q;
                q.push(i);
                color[i] = 0;
                int totColor[2];
                totColor[0] = 1;
                totColor[1] = 0;
                while(isBipartite && !q.empty())
                {
                    a = q.front();
                    q.pop();
                    for(int i=0;isBipartite && i<adjList[a].size();i++)
                    {
                        if(color[ adjList[a][i] ] == -1)
                        {
                            color[ adjList[a][i] ] = !color[a];
                            //printf("%d\n",!color[a]);
                            totColor[ color[ adjList[a][i] ] ]++;
                            q.push( adjList[a][i] );
                        }
                        else if(color[ adjList[a][i] ] == color[a])
                            isBipartite = false;
                    }
                }
                tot = tot + min(totColor[0], totColor[1]);
            }
        }
        //printf("Scenario #%d:\n",c);
        if(isBipartite)
            printf("%d\n", tot);
        else
            puts("-1");
    }
    return 0;
}
