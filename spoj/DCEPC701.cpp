#include <cstdio>
#include <queue>
#include <set>
#include <cstdlib>

#define SIZE 232
#define INF 2000000000
#define pii pair<int, pair<int, int> > 
#define pi pair<int, int> 

using namespace std;

int m,n;
bool visited[SIZE][SIZE];
int itime[SIZE][SIZE];
int imap[SIZE][SIZE];
int iwall[SIZE][SIZE];

template<typename t>
t getNum()
{
          t res=0;
          char c;
          int sign=1;
          while(1){
                   c=getchar_unlocked();
                   if(c==' '||c=='\n'||c=='.'||c=='#') continue;
                   else break;
                   }
          if (c=='+'){}
          else if(c=='-') sign=-1;
          else res=c-'0';
          while(1){
                   c=getchar_unlocked();
                   if(c>='0'&&c<='9') res=res*10+c-'0';
                   else break;
                   }
          return res*sign;
}

int dijkstra(int startx, int starty, int endx, int endy)
{
    itime[startx][starty] = 0;
    priority_queue<pii, vector<pii>, greater<pii> > pq;
    pq.push(pii(0, pi(startx, starty)));
    while(!pq.empty())
    {
        pii top = pq.top();
        pq.pop();
        int dist = top.first;
        int x = top.second.first;
        int y = top.second.second;
        visited[x][y] = true;
        if(x==endx && y == endy)
            return dist;
        if(itime[x][y] == dist)
        {
            if(x+1 < m && !visited[x+1][y])
            {
                int cost = dist + max(1, iwall[x+1][y]-dist);
                if(cost < itime[x+1][y])
                {
                    itime[x+1][y] = cost;
                    pq.push(pii(cost, pi(x+1, y)));
                }
            }
            if(x-1 >= 0 && !visited[x-1][y])
            {
                int cost = dist + max(1, iwall[x-1][y]-dist);
                if(cost < itime[x-1][y])
                {
                    itime[x-1][y] = cost;
                    pq.push(pii(cost, pi(x-1, y)));
                }
            }
            if(y+1 < n && !visited[x][y+1])
            {
                int cost = dist + max(1, iwall[x][y+1]-dist);
                if(cost < itime[x][y+1])
                {
                    itime[x][y+1] = cost;
                    pq.push(pii(cost, pi(x, y+1)));
                }
            }
            if(y-1 >= 0 && !visited[x][y-1])
            {
                int cost = dist + max(1, iwall[x][y-1]-dist);
                if(cost < itime[x][y-1])
                {
                    itime[x][y-1] = cost;
                    pq.push(pii(cost, pi(x, y-1)));
                }
            }
        }
    }
    return itime[endx][endy];
}

int main(){
    int t,a,b,c,d;
//    scanf("%d", &t);
    t = getNum<int>();
    while(t--)
    {
        //scanf("%d%d", &m, &n);
        m=getNum<int>();
        n=getNum<int>();
        //for(int i=0;i<m;i++)
        //{
            //scanf("%s", imap[i]);
            //for(int j=0;j<n;j++)
            //{
            //    imap[i][j] = getchar_unlocked();
            //}
            //getchar_unlocked();
        //}
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                //scanf("%d", &iwall[i][j]);
                iwall[i][j] = getNum<int>();
                itime[i][j] = INF;
                visited[i][j] = false;
            }
        }
        //scanf("%d%d%d%d", &a,&b,&c,&d);
        a = getNum<int>();
        b = getNum<int>();
        c = getNum<int>();
        d = getNum<int>();
        printf("%d\n", dijkstra(a,b,c,d));
    }
    return 0;
}

