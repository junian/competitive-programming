#include <cstdio>
#include <algorithm>

using namespace std;

int sw;

bool cmp(int a, int b)
{
    bool c=a<=b;
    if(c)
        sw++;
    return c;
}

int main()
{
    int x[500000];
    int n,i;
    while(1)
    {
        scanf("%d",&n);
        if(n==0)
            break;
        for(i=0;i<n;i++)
            scanf("%d",&x[i]);
        sw=0;
        sort(x,x+n,cmp);
        printf("%d\n",sw);
    }
    return 0;
}
