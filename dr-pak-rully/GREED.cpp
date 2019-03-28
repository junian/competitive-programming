#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

const int maxn = 503, maxm = 502001;
const int maxint = 0x7fffffff;
int n, m, card[maxn];
struct graph {
        int n, s, t, ec;
        struct edge_link {
                int v, r, w;
                edge_link *next, *pair;
        } edge[maxm], *header[maxn];
        int d[maxn], result;
        bool visited[maxn];

        void add_edge(int u, int v, int r, int w) {
                edge[++ec].v = v, edge[ec].r = r, edge[ec].w = w;
                edge[ec].next = header[u], header[u] = &edge[ec];
                edge[ec].pair = &edge[ec + 1];

                edge[++ec].v = u, edge[ec].r = 0, edge[ec].w = -w;
                edge[ec].next = header[v], header[v] = &edge[ec];
                edge[ec].pair = &edge[ec - 1];
        }

        void spfa() {
                queue<int> q;

                memset(visited, 0, sizeof(visited));
                d[s] = 0, q.push(s), visited[s] = true;
                while (!q.empty()) {
                        int u = q.front();
                        q.pop(), visited[u] = false;
                        for (edge_link *e = header[u]; e != NULL; e = e->next) {
                                if (e->r && d[u] + e->w < d[e->v]) {
                                        d[e->v] = d[u] + e->w;
                                        if (!visited[e->v]) {
                                                q.push(e->v), visited[e->v] = true;
                                        }
                                }
                        }
                }
                for (int i = 1; i <= n; ++i) {
                        d[i] = d[t] - d[i];
                }
        }

        int augument(int u, int flow) {
                if (u == t) {
                        result += d[s] * flow;
                        return flow;
                } else {
                        visited[u] = true;
                        for (edge_link *e = header[u]; e != NULL; e = e->next) {
                                if (e->r && !visited[e->v] && d[e->v] + e->w == d[u]) {
                                        int temp = augument(e->v, min(flow, e->r));
                                        if (temp) {
                                                e->r -= temp, e->pair->r += temp;
                                                return temp;
                                        }
                                }
                        }
                        return 0;
                }
        }

        int adjust() {
                int delta = maxint;

                for (int u = 1; u <= n; ++u) {
                        if (visited[u]) {
                                for (edge_link *e = header[u]; e != NULL; e = e->next) {
                                        if (e->r) {
                                                if (!visited[e->v] && d[e->v] + e->w > d[u]) {
                                                        delta = min(delta, d[e->v] + e->w - d[u]);
                                                }
                                        }
                                }
                        }
                }
                if (delta == maxint) {
                        return 0;
                } else {
                        for (int i = 1; i <= n; ++i) {
                                if (visited[i]) {
                                        d[i] += delta;
                                }
                        }
                        memset(visited, 0, sizeof(visited));
                        return delta;
                }
        }

        int min_cost_max_flow() {
                spfa();
                memset(visited, 0, sizeof(visited));
                do {
                        while (augument(s, maxint)) {
                                memset(visited, 0, sizeof(visited));
                        }
                } while (adjust());
                return result;
        }

        void init() {
                memset(edge, 0, sizeof(edge));
                memset(header, 0, sizeof(header));
                result = n = s = t = ec = 0;
                memset(d, 0x7f, sizeof(d));
        }
} g;

int main()
{
        int test_case, u, v;
        
        scanf("%d", &test_case);
        while (test_case--) {
                scanf("%d", &n);
                memset(card, 0, sizeof(card));
                for (int i = 1; i <= n; ++i) {
                        scanf("%d", &u);
                        ++card[u];
                }
                g.init();
                g.n = n + 2, g.s = n + 1, g.t = n + 2;
                for (int i = 1; i <= n; ++i) {
                        g.add_edge(g.s, i, card[i], 0);
                        g.add_edge(i, g.t, 1, 0);
                }
                scanf("%d", &m);
                for (int i = 1; i <= m; ++i) {
                        scanf("%d%d", &u, &v);
                        g.add_edge(u, v, maxint, 1);
                        g.add_edge(v, u, maxint, 1);
                }
                printf("%d\n", g.min_cost_max_flow());
        }
        return 0;
}
