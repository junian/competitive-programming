#include <cstdio>
int main()
{
    int x[100002];
    int y[100002];
    int i,j,n;
    bool t;
    while(1)
    {
        scanf("%d",&n);
        if(n==0)
            break;
        for(i=1;i<=n;i++)
        {
            scanf("%d",&x[i]);
            y[x[i]]=i;
        }
        t=true;
        for(i=1;i<=n;i++)
            if(x[i]!=y[i])
            {
                t=false;
                break;
            }
        if(t)
            printf("ambiguous\n");
        else
            printf("not ambiguous\n");
    }
    return 0;
}
