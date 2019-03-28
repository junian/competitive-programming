#include <cstdio>
int main()
{
    int c[10000];
    int n,t,i,m,s;
    while(1)
    {
        scanf("%d", &n);
        if(n==-1)
            break;
        t=0;m=0;
        for(i=0;i<n;i++)
        {
            scanf("%d",&c[i]);
            t+=c[i];
        }
        if(t%n!=0)
            printf("-1\n");
        else
        {
            s=t/n;
            m=0;
            for(i=0;i<n;i++)
            {
                if(c[i]>s)
                    m+=c[i]-s;
            }
            printf("%d\n",m);
        }
    }
    return 0;
}
