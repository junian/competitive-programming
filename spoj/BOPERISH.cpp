#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
    int p[1024],n,i,h;
    while(1)
    {
        scanf("%d",&n);
        if(n<=0)
            break;
        for(i=0;i<n;i++)
            scanf("%d",&p[i]);
        sort(p,p+n);
        h=n;
        for(i=0;i<n;i++)
            if(p[i]>=h)
                break;
            else
                h--;
        printf("%d\n",h);
    }
    return 0;
}
