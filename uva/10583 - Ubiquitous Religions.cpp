#include <cstdio>

#define MAX 50000

int set[MAX+1];
int size;

void initSet(int n) { size=n; for(int i=1;i<=n;i++) set[i] = i; }

int findSet(int i) { return set[i] = (set[i] == i ? i : findSet(set[i]) ); };

bool isSameSet(int a, int b) { return findSet(a) == findSet(b); }

void unionSet(int a, int b) { if(!isSameSet(a,b)) { set[findSet(a)] = findSet(b); size--; } };

int main()
{
    int n,a,b,c=0,m;
    while(scanf("%d%d",&n,&m),n,m)
    {
        c++;
        initSet(n);
        while(m--)
        {
            scanf("%d%d",&a,&b);
            unionSet(a,b);
        }
        printf("Case %d: %d\n",c,size);
    }
    return 0;
}
