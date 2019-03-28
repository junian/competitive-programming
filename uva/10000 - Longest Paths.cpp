#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

#define MAX 100


//int adjMatrix[MAX+1][MAX+1];
vector<int> adjList[MAX+32];
int depth[MAX+32];

//void dfs(int v, int length)
//{
//    for(int i=1;i<=n;i++)
//        if(adjMatrix[v][i] == 1)
//        {
//            if(length > max)
//            {
//                max = length;
//                end = v;
//            }
//            else if(length == max && v<end)
//                end = v;
//            dfs(i, length+1);
//        }
//}

void bfs(int v)
{
    queue<int> q;
    q.push(v);
    depth[v] = 0;
    while(!q.empty())
    {
        v = q.front();
        q.pop();
//        for(int i=1;i<=n;i++)
//            if(adjMatrix[v][i])
//            {
//                q.push(i);
//                depth[i] = depth[v]+1;
//            }
        for(unsigned int i=0;i<adjList[v].size();i++)
        {
            if(depth[v]+1 > depth[adjList[v][i]])
            {
                q.push(adjList[v][i]);
                depth[adjList[v][i]] = depth[v]+1;
            }
        }
    }
}

int main()
{
    int maxx=0,n=0;
    int end=0;
    int start=0,a=0,b=0,c=1;
    while(scanf("%d",&n)==1 && n)
    {
//        if(n <= 0)
//            break;
//        if(c!=1)
//            puts(" ");

        for(int i=1;i<=n;i++)
        {
            depth[i] = 0;
            adjList[i].clear();
//            for(int j=1;j<=n;j++)
//                adjMatrix[i][j] = 0;
        }

        scanf("%d",&start);

        maxx = 0;
        end = start;

        while(scanf("%d %d",&a,&b) == 2 && a && b)
//            adjMatrix[a][b] = 1;
            adjList[a].push_back(b);

        bfs(start);

        for(int i=1;i<=n;i++)
            if(depth[i]>maxx)
            {
                maxx = depth[i];
                end = i;
            }

        printf("Case %d: The longest path from %d has length %d, finishing at %d.\n\n",c,start,maxx,end);

        c++;
    }
    return 0;
}
