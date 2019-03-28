#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
    int x,y,z,i;
    int c=1;
    int m[10001];
    int n[10001];
    while(1)
    {
        scanf("%d%d",&x,&y);
        if(x==0 && y==0)
            break;
        for(i=0;i<x;i++)
            scanf("%d",&m[i]);

        sort(m,m+x);

        for(i=0;i<=10000;i++)
            n[i]=-1;
        for(i=x-1;i>=0;i--)
            n[m[i]]=i+1;

        printf("CASE# %d:\n",c);


        for(i=0;i<y;i++)
        {
            scanf("%d",&z);
            if(n[z]<0)
                printf("%d not found\n",z);
            else
                printf("%d found at %d\n",z,n[z]);
        }
        c++;
    }
    return 0;
}
