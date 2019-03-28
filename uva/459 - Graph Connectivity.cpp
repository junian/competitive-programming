#include <cstdio>
#include <vector>

using namespace std;

vector<char> set(1000);
int total_sets;

void initSet(char chr)
{
    for(char i='A';i<=chr;i++)
        set[i]=i;
    total_sets = (chr-'A')+1;
}

char findSet(char chr)
{
    if(set[chr] == chr)
        return chr;
    return (set[chr] = findSet(set[chr]));
}

bool isSameSet(char a, char b)
{
    return findSet(a)==findSet(b);
}

void unionSet(char a, char b)
{
    if(isSameSet(a,b))
        return;
    set[findSet(a)] = findSet(b);
    total_sets--;
}

int main()
{
    int t=0,i=0;
    char x[100];
    scanf("%d\n",&t);
    while(t--)
    {
        do{
            gets(x);
        }while(!x[0]);
        initSet(x[0]);
        while(gets(x))
        {
            if(x[0]=='\0')
                break;
            unionSet(x[0],x[1]);
        }
        printf("%d\n",total_sets);
        if(t)
            puts("");
    }

    return 0;
}
