#include <cstdio>
#include <algorithm>

#define MAX 128

using namespace std;

typedef struct Task
{
    int deathline;
    int penalty;
};

bool cmp(Task a, Task b)
{
    return b.penalty<a.penalty;
}

int main()
{
    int n,i,j;
    Task list[MAX], res[MAX];
    bool exist[MAX];
    while(scanf("%d",&n)!=EOF)
    {
        for(i=0;i<n;i++)
        {
            scanf("%d%d", &list[i].deathline, &list[i].penalty);
            exist[i]=false;
        }
        sort(list, list+n, cmp);
        for(i=0;i<n;i++)
        {
            j=list[i].deathline-1;
            while(exist[j])
                j=(j+n-1)%n;
            res[j] = list[i];
            exist[j]=true;
        }
        for(i=0;i<n;i++)
            printf("%d. %d %d\n",i+1,res[i].deathline,res[i].penalty);
    }
    return 0;
}
