#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>

using namespace std;

#define REP(i,n) for (int i=0,_n=n; i<_n; i++)
#define MAXN 2500

vector<int> con[MAXN];
int T,N,M,A,B;
char V[MAXN];

void dfs(int i){
    if (V[i]) return; else V[i] = 1;
    REP(j,con[i].size()) dfs(con[i][j]);
}

int main(){
    scanf("%d",&T);
    while (T--){
        scanf("%d %d",&N,&M);
        REP(i,N) con[i].clear();
        REP(i,M){
            scanf("%d %d",&A,&B);
            con[A-1].push_back(B-1);
        }
        int cnt = 0;
        REP(i,N){
            memset(V,0,sizeof(V));
            REP(j,con[i].size()) dfs(con[i][j]);
            REP(j,N) if (i!=j && V[j]) cnt++;
        }
        printf("%d\n",cnt);
    }
}
