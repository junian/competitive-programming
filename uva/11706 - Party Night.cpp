
#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

#define MAX 200

int main()
{
    vector<int> adjList[MAX];
    int color[MAX];
    int n,m,a,b;
    bool isBipartite;

    while(scanf("%d",&n),n)
    {
        for(int i=0;i<n;i++)
            adjList[i].clear(),color[i]=-1;
        isBipartite = true;
        scanf("%d",&m);
        while(m--)
        {
            scanf("%d%d",&a,&b);
            adjList[a].push_back(b);
           // adjList[b].push_back(a);
        }
        queue<int> q;
        q.push(0);
        color[0] = 0;
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
        if(isBipartite)
            puts("YES");
        else
            puts("NO");
    }
    return 0;
}
