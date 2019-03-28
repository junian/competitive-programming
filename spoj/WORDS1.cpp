//#include <cstdio>
//#include <cstring>
//
//#define MAX 26
//
//int visits[MAX][MAX];
//int adjMatrix[MAX][MAX];
//int n;
//
//void clearArray(int arr[MAX][MAX])
//{
//    for(int i=0;i<MAX;i++)
//        for(int j=0;j<MAX;j++)
//            arr[i][j] = 0;
//}
//
//bool dfs(int x, int connected)
//{
//    if(connected == n)
//        return true;
//    for(int i=0;i<MAX;i++)
//    {
//        if(visits[x][i]<adjMatrix[x][i])
//        {
//            visits[x][i]++;
//            if(dfs(i,connected+1))
//                return true;
//            visits[x][i]--;
//        }
//    }
//    return false;
//}
//
//int main()
//{
//    int t;
//    char s[1024];
//    bool ok;
//    scanf("%d",&t);
//    while(t--)
//    {
//        scanf("%d",&n);
//        ok = false;
//        clearArray(visits);
//        clearArray(adjMatrix);
//        for(int i=0;i<n;i++)
//        {
//            scanf("%s",s);
//            adjMatrix[s[0]-'a'][s[strlen(s)-1]-'a']++;
//        }
//        for(int i=0;i<MAX;i++)
//        {
//            if(dfs(i,0))
//            {
//                ok=true;
//                break;
//            }
//        }
//        if(ok)
//            puts("Ordering is possible.");
//        else
//            puts("The door cannot be opened.");
//    }
//    return 0;
//}


#include <cstdio>
#include <cstring>

#define MAX 26

int indegree[MAX];
int outdegree[MAX];
int set[MAX];

void initSet()
{
    for(int i=0;i<MAX;i++)
    {
        indegree[i] = outdegree[i] = 0;
        set[i] = i;
    }
}

int findSet(int i)
{
    return (set[i] = (set[i]==i ? i : findSet(set[i])));
}

void unionSet(int a, int b)
{
    set[findSet(a)] = findSet(b);
}

int main()
{
    int t,n,start,end,i,tmp,a,b;
    bool isEuler;
    char s[1024];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        initSet();
        isEuler = true;
        start = end = 0;

        for(i=0;i<n;i++)
        {
            scanf("%s",s);
            a=s[0]-'a';
            b=s[strlen(s)-1]-'a';
            outdegree[a]++;
            indegree[b]++;
            unionSet(b,a);
        }

        for(i=0;i<MAX;i++)
            if(indegree[i] + outdegree[i] != 0)
            {
                tmp = findSet(i);
                break;
            }

        for(;i<MAX;i++)
            if((indegree[i] + outdegree[i] != 0) && (findSet(i)!=tmp))
            {
                isEuler = false;
                break;
            }

        for(i=0;isEuler && (i<MAX);i++)
        {
            int diff = outdegree[i]-indegree[i];
            if(diff == 1)
                start++;
            else if(diff == -1)
                end++;
            else if(diff!=0)
                isEuler = false;
        }

        if(isEuler && (start+end==2 || start+end==0))
            puts("Ordering is possible.");
        else
            puts("The door cannot be opened.");
    }
    return 0;
}
