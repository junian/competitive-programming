#include <cstdio>
#include <vector>
#include <algorithm>
#include <math.h>
#include <queue>
#include <string.h>

#define MAX 100001
#define NIL 0
#define INF (1<<28)

using namespace std;


vector< int > G[MAX];
int n, m, match[MAX], dist[MAX];
// n: number of nodes on left side, nodes are numbered 1 to n
// m: number of nodes on right side, nodes are numbered n+1 to n+m
// G = NIL[0] ? G1[G[1---n]] ? G2[G[n+1---n+m]]

bool bfs() {
    int i, u, v, len;
    queue< int > Q;
    for(i=1; i<=n; i++) {
        if(match[i]==NIL) {
            dist[i] = 0;
            Q.push(i);
        }
        else dist[i] = INF;
    }
    dist[NIL] = INF;
    while(!Q.empty()) {
        u = Q.front(); Q.pop();
        if(u!=NIL) {
            len = G[u].size();
            for(i=0; i<len; i++) {
                v = G[u][i];
                if(dist[match[v]]==INF) {
                    dist[match[v]] = dist[u] + 1;
                    Q.push(match[v]);
                }
            }
        }
    }
    return (dist[NIL]!=INF);
}

bool dfs(int u) {
    int i, v, len;
    if(u!=NIL) {
        len = G[u].size();
        for(i=0; i<len; i++) {
            v = G[u][i];
            if(dist[match[v]]==dist[u]+1) {
                if(dfs(match[v])) {
                    match[v] = u;
                    match[u] = v;
                    return true;
                }
            }
        }
        dist[u] = INF;
        return false;
    }
    return true;
}

int hopcroft_karp() {
    int matching = 0, i;
    // match[] is assumed NIL for all vertex in G
    memset(match,0,sizeof(match));
    while(bfs())
        for(i=1; i<=n; i++)
            if(match[i]==NIL && dfs(i))
                matching++;
    return matching;
}

typedef struct point
{
    int x,y;
};

typedef struct line
{
    int red,blue;
    int length;
};

bool cmp(line a, line b)
{
    return a.length < b.length;
}

int main()
{
    int t,nn,mm,a,b,sol,solu;
    bool ismatch;
    char col[16];
    scanf("%d",&t);
    while(t--)
    {
        vector<point> reds;
        vector<point> blues;
        vector<line> lines;
        scanf("%d%d", &nn, &mm);
        for(int i=0;i<nn;i++)
        {
            scanf("%d %d %s", &a, &b, col);
            point pt;
            pt.x=a;
            pt.y=b;
            if(col[0] == 'r')
                reds.push_back(pt);
            else
                blues.push_back(pt);
        }
        for(int i=0;i<reds.size();i++)
        {
            for(int j=0;j<blues.size();j++)
            {
                line l;
                l.red = i;
                l.blue = j;
                l.length = ceil(sqrt((reds[i].x-blues[j].x)*(reds[i].x-blues[j].x) + (reds[i].y-blues[j].y)*(reds[i].y-blues[j].y)));
                lines.push_back(l);
//              if(l.length<=4)
//                G[i+1].push_back(j+reds.size()+1);
            }
        }
        n=reds.size();
        m=blues.size();
        //printf("match: %d\n",hopcroft_karp());
        sort(lines.begin(), lines.end(), cmp);
        int lo=0, hi=lines.size();
        //while(lo<hi)
        ismatch=false;
        for(int aa=0;aa<lines.size();aa++)
        {
            G[0].clear();
            for(int i=0;i<reds.size();i++)
            {
                G[i+1].clear();
            }
            //int mid = (lo+hi)/2;
            sol=lines[aa].length;
            for(int i=0;i<lines.size();i++)
            {
               if(lines[i].length<=sol)
                 G[lines[i].red+1].push_back(lines[i].blue+1+reds.size());
            }
            solu = hopcroft_karp();
            //printf("sol:%d match: %d\n",sol,solu);
            if(solu >= mm)
            {
                printf("%d\n", sol);
                ismatch = true;
                break;
            }
            //if(solu >= mm)
                //lo = mid+1;
            //else
                //hi = mid;
        }
        if(!ismatch)
            puts("Impossible");
        //for(int i=0;i<lines.size();i++)
            //printf("%d %d %d\n", lines[i].red, lines[i].blue, lines[i].length);
    }
    return 0;
}
