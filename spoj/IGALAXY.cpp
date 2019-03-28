#include <iostream>
#include <cstdio>
#include <queue>
#include <string>
#include <vector>
#include <map>

#define INF 2000000000

using namespace std;

int T, R;
string P, Q, S, D;

class pis
{
public:
    int dis;
    string name;
    pis(int d, string n)
    :dis(d),name(n)
    {
    }
    friend bool operator < (const pis& x, const pis& y)
    {
        if(x.dis == y.dis)
            return x.name > y.name;
        return x.dis>y.dis;
    }
};

map<string, string> next;
map<string, vector<string> > adjList;
map<string, int> dist;

void dijkstra()
{
    dist[S] = 0;
    priority_queue<pis> pq;
    pq.push(pis(0,S));
    while(!pq.empty())
    {
        pis top = pq.top();
        pq.pop();
        if(top.dis==INF || top.name == D)
            break;
        vector<string> list = adjList[top.name];
        for(int i=0;i<list.size();i++)
        {
            int alt = dist[top.name] + 1;
            cout<<next[S]<<endl;
            if(alt < dist[list[i]])
            {
                if(next[top.name] == "")
                {
                    dist[list[i]] = alt;
                    next[top.name] = list[i];
                    pq.push(pis(alt, list[i]));
                }
            }
        }
    }
}

int main()
{
    scanf("%d", &T);
    for(int sc = 1; sc<=T; sc++)
    {
        next.clear();
        adjList.clear();
        dist.clear();
        scanf("%d", &R);
        //priority_queue<pis> pq;
        while(R--)
        {
            cin >> P >> Q;
            adjList[P].push_back(Q);
            adjList[Q].push_back(P);
            dist[P] = dist[Q] = INF;
            next[P] = next[Q] = "";
            //pq.push(pis(1, P));
            //pq.push(pis(2, Q));
        }
        cin >> S >> D;
        dist[S] = dist[D] = INF;
        dijkstra();
        string solution = "";
        int shortest = dist[D] == INF? -1: dist[D]+1;
        printf("Scenario #%d: %d\n", sc, shortest);
        if(shortest!=-1)
        {
            solution = S;
            for(int i=1;i<shortest;i++)
            {
                solution = solution + " " + next[S];
                S = next[S];
            }
            //solution = S + " " + solution;
            printf("%s\n", solution.c_str());
        }
        
    }
    return 0;
}

