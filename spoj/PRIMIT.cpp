#include <cstdio>

#define MAX 1000

int set[MAX+2];
int indegree[MAX+2];
int outdegree[MAX+2];

void initSet()
{
    for(int i=1;i<=MAX;i++)
    {
        set[i] = i;
        indegree[i] = outdegree[i] = 0;
    }
}

int findSet(int i)
{
    return set[i] = (set[i]==i?i:findSet(set[i]));
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
    int n,t,a,b,tmpSet,i,
        endpoint,
        outdegrees,needin,needout,
        indegrees;
    scanf("%d",&t);

    while(t--)
    {
        scanf("%d",&n);
        initSet();
        indegrees = outdegrees = endpoint = 0;
        needin = needout = 0;
        while(n--)
        {
            scanf("%d%d",&a,&b);
            outdegree[a]++;
            indegree[b]++;
            unionSet(a,b);
        }
//        for(i=1;i<=MAX;i++)
//            if(indegree[i]|outdegree[i])
//            {
//                tmpSet = findSet(i);
//                break;
//            }
//        for(;i<=MAX;i++)
//            if(indegree[i]|outdegree[i])
//                if(!isSameSet(tmpSet,i))
//                {
//                    indegree[findSet(tmpSet)]++;
//                    //indegree[findSet(i)]++;
//                    //outdegree[findSet(tmpSet)]++;
//                    outdegree[findSet(i)]++;
//                    unionSet(tmpSet,i);
//                }
        for(i=1;i<=MAX;i++)
        {
            if(indegree[i]|outdegree[i])
            {
                int diff = outdegree[i]-indegree[i];
                if(diff<0)
                    needout -= diff;
                else if(diff>0)
                    needin += diff;

                //outdegrees += outdegree[i];
                indegrees += indegree[i];
            }
        }
        for(i=1;i<=MAX;i++)
            if(indegree[i]|outdegree[i])
            {
                tmpSet = findSet(i);
                break;
            }
        for(;i<=MAX;i++)
            if(indegree[i]|outdegree[i])
                if(!isSameSet(tmpSet,i))
                {
                    needin++;
                    //indegree[findSet(tmpSet)]++;
                    //indegree[findSet(i)]++;
                    //outdegree[findSet(tmpSet)]++;
                    //outdegree[findSet(i)]++;
                    needout++;
                    unionSet(tmpSet,i);
                }
        if(needin+needout>2)
        {
            needin--;
            needout--;
        }
        printf("%d\n",indegrees+(needin+needout)/2+1);
    }

    return 0;
}
