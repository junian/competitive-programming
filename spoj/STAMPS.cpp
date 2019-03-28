#include <cstdio>
#include <cstdlib>

int compare(const void*a,const void*b)
{
    return (*(int*)b-*(int*)a);
}
int main()
{
    int m[1000];
    int t,i,n,tot,j,f;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%d%d",&tot,&n);
        for(j=0;j<n;j++)
            scanf("%d",&m[j]);
        qsort(m,n,sizeof(int),compare);
        f=0;
        for(j=0;j<n;j++)
        {
            if(tot<=0)
                break;
            f++;
            tot-=m[j];
        }
        if(tot<=0)
            printf("Scenario #%d:\n%d\n\n",i,f);
        else
            printf("Scenario #%d:\nimpossible\n\n",i);
    }
    return 0;
}
