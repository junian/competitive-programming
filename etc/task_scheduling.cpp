#include <cstdio>
#include <algorithm>

#define MAX 10000

using namespace std;

typedef struct task
{
    int deadline, penalty, index;
};

bool cmp(task a, task b)//sorting compare
{
    return a.penalty > b.penalty;
}

int main()
{
    int n,i,j,total_penalty=0;
    task tasks[MAX];
    int schedule[MAX];

    scanf("%d",&n);

    for(i=1;i<=n;i++)
    {
        scanf("%d%d",&tasks[i].deadline,&tasks[i].penalty);
        tasks[i].index = i;//task keberapa?
        schedule[i] = 0;
    }

    sort(tasks+1, tasks+n+1, cmp);//sorting

    for(i=1;i<=n;i++)
    {
        j = tasks[i].deadline;
        while(1)
        {
            if(schedule[j] == 0)
            {
                schedule[j] = i;
                break;
            }
            j = (n+j-2)%n + 1;
        }
    }

    for(i=1;i<=n;i++)
    {
        printf("hari ke-%d - task ke-%d - deadline: %d penalty: %d\n", i, tasks[schedule[i]].index, tasks[schedule[i]].deadline, tasks[schedule[i]].penalty);
        if(tasks[schedule[i]].deadline < i)
            total_penalty += tasks[schedule[i]].penalty;
    }
    printf("total penalty: %d\n", total_penalty);
    return 0;
}
