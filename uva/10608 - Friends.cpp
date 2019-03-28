#include <cstdio>

#define MAX 30001

int set[MAX];
int total[MAX];
//int initSize;
//int currentSize;

void initSet(int n)
{
//    initSize = currentSize = n;
    for(int i=1;i<=n;i++)
    {
        set[i] = i;
        total[i] = 0;
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
    if(!isSameSet(a,b))
        set[findSet(a)] = findSet(b);
}

int main()
{
    int t,m,n,a,b,max;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        initSet(n);
        while(m--)
        {
            scanf("%d%d",&a,&b);
            unionSet(a,b);
        }
        max=1;
        for(int i=1;i<=n;i++)
        {
            total[findSet(i)]++;
            max = total[findSet(i)]>max ? total[findSet(i)] : max;
        }
        printf("%d\n",max);
    }
}
