#include <cstdio>

#define MAX 10000

int set[MAX+1];
int size;

void initSet(int n) { size=n; for(int i=1;i<=n;i++) set[i] = i; }

int findSet(int i) { return set[i] = (set[i] == i ? i : findSet(set[i]) ); };

bool isSameSet(int a, int b) { return findSet(a) == findSet(b); }

void unionSet(int a, int b) { if(!isSameSet(a,b)) { set[findSet(a)] = findSet(b); size--; } };

int main()
{
    int n,m,a,b;
    bool isTree = true;
    scanf("%d%d",&n,&m);
    initSet(n);
    while(m--)
    {
        scanf("%d%d",&a,&b);
        if(isSameSet(a,b)) isTree = false;
        unionSet(a,b);
    }
    if(size!=1)
        isTree = false;
    if(isTree)
        puts("YES");
    else
        puts("NO");
    return 0;
}
