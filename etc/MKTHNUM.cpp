#include <cstdio>
#include <cstdlib>

int compare(const void *a,const void *b)
{
    return (*(int*)a-*(int*)b);
}

int main()
{
    int x[100000];
    int y[100000];
    int m,n,a,b,c,d,e,f,i,j;
    scanf("%d%d",&m,&n);
    for(i=0;i<m;i++)
        scanf("%d",&x[i]);
    for(i=0;i<n;i++)
    {
        scanf("%d%d%d",&a,&b,&c);
        b--;a--;
        f=b-a+1;
        for(j=0;j<f;j++)
            y[j]=x[j+a];
        qsort(y,f,sizeof(int),compare);
        printf("%d\n",y[c-1]);
    }
    return 0;
}
