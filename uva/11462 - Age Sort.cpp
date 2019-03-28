#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
    char n[2000001];
    int x,i;
    while(1)
    {
        scanf("%d",&x);
        if(x==0)
            break;
        for(i=0;i<x;i++)
            scanf("%d",&n[i]);
        sort(n,x+n);
        printf("%d",n[0]);
        for(i=1;i<x;i++)
            printf(" %d",n[i]);
        printf("\n");
    }
    return 0;
}
