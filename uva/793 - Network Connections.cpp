#include <cstdio>
#include <vector>

using namespace std;

typedef unsigned int ui;

vector<int> comp_set;

void initSet(int size)
{
    comp_set.resize(size);
    for(int i=0;i<size; i++)
        comp_set[i] = i;
}

int findSet(int i)
{
    if(i == comp_set[i])
        return i;
    return (comp_set[i] = findSet(comp_set[i]));
}

bool isSameSet(int a, int b)
{
    return findSet(a)==findSet(b);
}

void unionSet(int a, int b)
{
    comp_set[findSet(a)] = findSet(b);
}

int main()
{
    int t,a,b,c,n1,n2;
    char x[3],s[256];
    scanf("%d\n",&t);
    while(t--)
    {
        scanf("%d\n",&a);
        n1 = n2 = 0;
        initSet(a);
        while(gets(s))
        {
            if(!s[0])
                break;
            sscanf(s,"%s %d %d\n",x,&b,&c);
            if(x[0] == 'q')
            {
                if(isSameSet(b-1,c-1))
                    n1++;
                else
                    n2++;
            }
            else
                unionSet(b-1,c-1);


        }
        printf("%d,%d\n",n1,n2);
        if(t)
            puts("");
    }
    return 0;
}
