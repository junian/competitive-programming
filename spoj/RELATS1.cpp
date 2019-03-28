#include <cstdio>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

#define MAX 1024

bool visited[MAX+1];
int point[MAX+1];
vector< pair<int, int> > adjList[MAX+1];
bool isOk;
int N;

void init(int n)
{
    isOk = true;
    for(int i=1;i<=n;i++)
        adjList[i].clear();
    memset(visited,false,sizeof(visited));
    memset(point,0,sizeof(point));
    N = n;
}

int main()
{
    int m,t,n;
    scanf("%d",&t);
    int a,b,c;
    while(t-->0)
    {
        scanf("%d%d",&n,&m);
        init(n);
        while(m--)
        {
            scanf("%d%d%d",&a,&b,&c);
            adjList[a].push_back( make_pair(b,c) );
        }
        for(int i=1;i<=n;i++)
        {
            if(!visited[i] && isOk)
            {
                queue<int> q;
                int a;
                visited[i] = true;
                point[i] = 0;
                q.push(i);
                while(!q.empty() && isOk)
                {
                    a = q.front();
                    q.pop();
                    for(int j=0;j<adjList[a].size() && isOk; j++)
                    {
                        if(!visited[ adjList[a][j].first ])
                        {
                            visited[ adjList[a][j].first ] = true;
                            point[ adjList[a][j].first ] = point[a] - adjList[a][j].second;
                            q.push( adjList[a][j].first );
                        }
                        else
                        {
                            if(adjList[a][j].second == 0 && point[ adjList[a][j].first ] - point[ a ] != 0)
                                isOk = false;
                            else if( adjList[a][j].second == 1 && point[a] < point[ adjList[a][j].first ] )
                                isOk = false;
                            else if( adjList[a][j].second == -1 && point[a] > point[ adjList[a][j].first ] )
                                isOk = false;

                        }
                    }
                }
            }
        }
        if(!isOk)
            puts("NO");
        else
        {
            int mini, maxi;
            mini = maxi=point[1];
            for(int i=2;i<=n;i++)
            {
                if(point[i]<mini)
                    mini = point[i];
                if(point[i]>maxi)
                    maxi = point[i];
            }
            printf("%d\n",maxi-mini);
        }
    }
    return 0;
}
