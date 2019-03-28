#include <cstdio>
#include <cstdlib>

int compare(const void*a, const void*b)
{
    return (*(int*)a - *(int*)b);
}
int main()
{
    bool j;
    int n,i,def;
    int x[3000];
    int d[3000];
    while(scanf("%d",&n)!=EOF)
    {
        scanf("%d",&x[0]);
        for(i=1;i<n;i++)
        {
            scanf("%d",&x[i]);
            if(x[i]>x[i-1])
            {
                def=x[i]-x[i-1];
            }
            else
                def=x[i-1]-x[i];
            d[i-1]=def;
        }
        if(n>1)
        {
            qsort(d,n-1,sizeof(int),compare);
        }
        j=true;
        for(i=0;i<n-1;i++)
        {
            if(d[i]!=i+1)
            {
                j=false;
                break;
            }
        }
        if(j)
            printf("Jolly\n");
        else
            printf("Not jolly\n");

    }
    return 0;
}
