#include <cstdio>
#include <map>

using namespace std;

map<int, int> x;
int r[500001];

int main()
{
    r[0]=0;
    x.clear();
    int i;
    for(i=1;i<=500000;i++)
    {
        if(r[i-1]-i>0 && x[r[i-1]-i]==0)
            r[i]=r[i-1]-i;
        else
            r[i]=r[i-1]+i;
        x[r[i]]=i;
    }
    while(1)
    {
        scanf("%d",&i);
        if(i<0)
            break;
        printf("%d\n",r[i]);
    }
    return 0;
}
