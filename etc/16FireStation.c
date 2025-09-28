#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXV = 505, INFINITY = 999999999;
int gv, adj[MAXV][MAXV], cst[MAXV], parnt[MAXV];
bool fs[MAXV];

int pq[MAXV+1], qp[MAXV], N;
void exch(int i, int j) { swap(pq[i], pq[j]); qp[pq[i]] = i; qp[pq[j]] = j; }
void fixdown(int i)
{
    int j;
    while(2*i <= N) {
        j = 2*i;
        if(j < N && cst[ pq[j] ] > cst[ pq[j+1] ]) j++;
        if(cst[ pq[i] ] <= cst[ pq[j] ]) break;
        exch(i,j);
        i = j;
    }
}
void fixup(int i)
{
    while(i > 1 && cst[ pq[i] ] < cst[ pq[i/2] ]) {
        exch(i, i/2);
        i /= 2;
    }
}
void pq_init() { N=0; }
bool pq_empty() { return (N==0); }
void pq_insert(int v) { qp[v]=++N; pq[N]=v; fixup(N); }
int pq_delmin() { exch(1,N); N--; fixdown(1); return pq[N+1]; }
void pq_dec(int v) { fixup(qp[v]); }

int dijkstra()
{
    int v, w;

    for(v=0; v<gv; v++) {
        cst[v] = INFINITY;
        parnt[v] = -1;
    }

    pq_init();
    for(v=0; v<gv; v++) {
        if(fs[v]) {
            cst[v] = 0;
            parnt[v] = v;
            pq_insert(v);
        }
    }

    while(!pq_empty()) {
        v = pq_delmin();
        for(w=0; w<gv; w++) {
            if(adj[v][w] < INFINITY) {

                if(cst[w] == INFINITY) {
                    cst[w] = cst[v] + adj[v][w];
                    parnt[w] = v;
                    pq_insert(w);
                }
                else if(cst[w] > cst[v] + adj[v][w]) {
                    cst[w] = cst[v] + adj[v][w];
                    parnt[w] = v;
                    pq_dec(w);
                }

            }
        }
    }

    return *max_element(cst, cst+gv);
}


int main()
{
    int t, f, i, j, k, x, u, v, ci;
    int value, best_value, best_vertex;
    char line[1024];

    gets(line);
    sscanf(line, "%d", &t);
    gets(line);

    while(t--) {
        // input
        gets(line);
        sscanf(line, "%d %d", &f, &i);

        gv = i;
        fill(fs, fs+gv, false);
        for(j=0; j<f; j++) {
            gets(line);
            sscanf(line, "%d", &x);
            fs[x-1] = true;
        }

        for(j=0; j<gv; j++) {
            for(k=0; k<gv; k++)
                adj[j][k] = INFINITY;
        }

        while(gets(line) && *line) {
            sscanf(line, "%d %d %d", &u, &v, &ci);
            u--; v--;
            adj[u][v] = adj[v][u] = ci;
        }

        // processamento
        best_vertex = 0;
        best_value = INFINITY;
        for(v=0; v<gv; v++) {
            // v e' candidato a nova estacao
            if(!fs[v]) {
                fs[v] = true;
                value = dijkstra();
                if(value < best_value) {
                    best_value = value;
                    best_vertex = v;
                }
                fs[v] = false;
            }
        }

        // output
        printf("%d\n", best_vertex+1);
        if(t > 0) printf("\n");
    }

    return 0;
}
