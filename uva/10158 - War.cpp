#include <cstdio>
#define FRIEND
int people[10000];

void initSet(int size)
{
    for(int i=0;i<size;i++)
        people[i] = i;
}

int findSet(int i)
{
    if(i==people[i]) return i;
    return (people[i] = findSet(people[i]));
}

bool isSameSet(int a, int b)
{
    return findSet(a) == findSet(b);
}

int main()
{
    return 0;
}
