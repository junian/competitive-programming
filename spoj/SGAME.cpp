#include<cstdio>

#define MAX 301

int degree[MAX];
int set[MAX];

void init_set()
{
    for(int i=0;i<MAX;i++)
    {
        degree[i] = 0;
        set[i] = i;
    }
}

int find_set(int i)
{
    return (set[i] = (set[i]==i ? i : find_set(set[i])));
}

void union_set(int a, int b)
{
    set[find_set(a)] = find_set(b);
}

int main()
{
    int T,start,a,b, total;
    scanf("%d", &T);
    while(T--)
    {
        init_set();
        total = 0;
        scanf("%d", &start);
        while(1)
        {
            scanf("%d%d", &a, &b);
            if(a<0 && b<0)
                break;
            degree[a]++; degree[b]++;
            union_set(a,b);
        }
        bool euler = true;
        int tmp,i;
        for(i=0;i<MAX;i++){
            if(degree[i] != 0)
            {
                tmp = find_set(i);
                break;
            }
        }
        for(;i<MAX;i++){
            if((degree[i] != 0) && (find_set(i)!=tmp))
            {
                euler = false;
                break;
            }
        }
        for(i=0;euler && (i<MAX);i++)
        {
            if(degree[i]%2!=0)
                euler = false;
        }
        if(euler)
            puts("YES");
        else
            puts("NO");
    }
    return 0;
}
