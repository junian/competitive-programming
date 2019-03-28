
//you can change max set size
#define MAX 10000

int set[MAX];
int setSize;

void initSet(int size)
{
    //init that every element is disjoint set
    for(int i=0;i<size;i++)
        set[i] = i;
    //total sets is equal to total elements
    setSize = size;
}

int findSet(int i)
{
    //means that set[i] is disjoint set
    if(set[i] == i)
        return i;
    //set this set to parent set
    return (set[i] = findSet(set[i]));
}

bool isSameSet(int a, int b)
{
    //same set means same parent
    return findSet(a) == findSet(b);
}

void unionSet(int a, int b)
{
    if(!isSameSet(a,b))
    {
        //union set, so a and b became one set
        set[findSet(a)] = findSet(b);
        //reduce set size;
        setSize--;
    }
}

