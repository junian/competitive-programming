#include <cstdio>
#define max(a,b) a>b?a:b
#define min(a,b) a<b?a:b

int main()
{
    register unsigned int p[100],q[100];
    register unsigned int a,b,i,j,m,n,o;
    while(1)
    {
        scanf("%u%u",&a,&b);
        if(a==0 && b==0)
            break;
        m=max(a-b,b);
        n=min(a-b,b);
        if(n==0)
            n++;
        o=m+1;
        for(i=0;i<a-m;i++)
            p[i]=o++;
        o=a-m;
        for(i=1;i<=n;i++)
            q[i-1]=i;
        for(i=0; i<n;i++)
        {
            for(j=0;j<o;j++)
            {
                if(q[i] > 1 && p[j]%q[i] == 0)
                {
                    p[j]/=q[i];
                    q[i]
                }
            }
        }
    }
    return 0;
}
