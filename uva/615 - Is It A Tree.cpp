#include <cstdio>
#include <map>

using namespace std;

map<int,int> set;

void initSet() { set.clear(); }

int findSet(int i) { if(set[i]==0) set[i]=i; return set[i] = (set[i] == i ? i : findSet(set[i]) ); };

bool isSameSet(int a, int b) { return findSet(a) == findSet(b); }

void unionSet(int a, int b) { if(!isSameSet(a,b)) { set[findSet(a)] = findSet(b); } };

int main()
{
    int a,b,c=0;
    bool isTree;
    while(true)
    {
        scanf("%d%d",&a,&b);
        if(a<0 && b<0)
            break;
        initSet();
        isTree = true;
        c++;
        do
        {
            if(a == 0 && b == 0)
                break;
            if(isSameSet(a,b))
                isTree = false;
            unionSet(a,b);
            scanf("%d%d",&a,&b);

        }while(true);

        map<int,int>::iterator iter;
        iter = set.begin();
        int tmp = findSet(iter->first);
        ++iter;
        for( ;isTree && iter != set.end(); ++iter )
            if(findSet(iter->first) != findSet(tmp))
                isTree = false;
        if(isTree)
            printf("Case %d is a tree.\n",c);
        else
            printf("Case %d is not a tree.\n",c);

    }
    return 0;
}
