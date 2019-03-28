#include <cstdio>

#define MAX 200

int set[MAX];
int deg[MAX];

void initSet(int n)
{
    for(int i=0;i<n;i++)
    {
        set[i] = i;
        deg[i] = 0;
    }
}

int findSet(int i)
{
    return set[i] = (set[i] == i ? i : findSet(set[i]));
}

bool isSameSet(int a, int b)
{
    return findSet(a) == findSet(b);
}

void unionSet(int a, int b)
{
    set[findSet(a)] = findSet(b);
}

int main()
{
    bool isEuler;
    int n,r,tmp,a,b,i;
    while(scanf("%d%d",&n,&r)!=EOF)
    {
        initSet(n);
        isEuler = true;
        while(r--)
        {
            scanf("%d%d",&a,&b);
            deg[a]++;
            deg[b]++;
            unionSet(a,b);
        }
        tmp = findSet(0);
        if(deg[0]%2!=0) isEuler = false;
        for(i=1;isEuler && i<n;i++)
            if(!isSameSet(tmp,i) || deg[i]%2!=0)
                isEuler = false;
        if(isEuler)
            puts("Possible");
        else
            puts("Not Possible");
    }

    return 0;
}
