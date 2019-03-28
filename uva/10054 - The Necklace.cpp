#include <cstdio>
#include <cstring>
//#include <queue>
#include <stack>

using namespace std;

#define C 51

int set[C];
int degree[C];
int adjMatrix[C][C];
int steps[C][C];
//queue< pair<int, int> > solution;
stack<int> tour;

void init()
{
    memset(degree,0,sizeof(int)*C);
    for(int i=0;i<C;i++)
    {
        set[i] = i;
        memset(adjMatrix[i],0,sizeof(int)*C);
        memset(steps[i],0,sizeof(int)*C);
    }
//    while(!solution.empty())
//        solution.pop();
    while(!tour.empty())
        tour.pop();
}

int findSet(int i)
{
    return set[i] = (set[i] == i ? i : findSet(set[i]));
}

bool isSameSet(int a, int b)
{
    return findSet(a) == findSet(b);
}

void unionSet(int a, int b)
{
    set[findSet(a)] = findSet(b);
}

void euler_tour(int v)
{
    for(int i=1;i<C;i++)
    {
        if(steps[v][i]<adjMatrix[v][i])
        {
//            solution.push( make_pair(v,i) );
            steps[v][i]++;
            steps[i][v]++;
            euler_tour(i);
        }
    }
    tour.push(v);
}

int main()
{
    int t, n, c, x, y, tmp,i;
    int start,finish,altstart;
    bool isEuler;
    scanf("%d",&t);

    for( c=1; c<=t; c++ )
    {
        scanf("%d",&n);
        init();
        isEuler = true;
        altstart = start = finish = 0;

        while(n--)
        {
            scanf("%d%d",&x,&y);
            unionSet(x,y);
            adjMatrix[x][y]++;
            adjMatrix[y][x]++;
            degree[x]++;
            degree[y]++;
        }

        for(i=1;i<C;i++)
            if(degree[i]!=0)
            {
                altstart = i;
                tmp = findSet(i);
                break;
            }

        for(;isEuler && i<C;i++)
            if(degree[i]!=0 && !isSameSet(i, tmp))
                isEuler = false;

//        printf("isEuler = %d\n",isEuler);
        for(i=1;isEuler && i<C;i++)
        {
            if(degree[i]%2 != 0)
            {
//                if(start == 0)
//                    start = i;
//                else if(finish == 0)
//                    finish = i;
//                else
                    isEuler = false;
            }
        }
//        printf("isEuler = %d\n",isEuler);
//        if( (start==0 || finish==0) && start+finish != 0)
//            isEuler = false;
//        printf("isEuler = %d\n",isEuler);
        if(isEuler)
        {
//            if(start!=0)
//                euler_tour(start);
//            else
                euler_tour(altstart);
        }
//        printf("isEuler = %d\n",isEuler);
        printf("Case #%d\n", c);
        if(!isEuler)
            puts("some beads may be lost");
        else
        {
//            while(!solution.empty())
//            {
//                pair< int, int > sol = solution.front();
//                printf("%d %d\n",sol.first, sol.second);
//                solution.pop();
//            }
            int first = tour.top();
            tour.pop();
            while(!tour.empty())
            {
                printf("%d %d\n",first,tour.top());
                first = tour.top();
                tour.pop();
            }
        }
        if(c<t)
            puts("");

    }
    return 0;
}
