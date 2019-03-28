#include <cstdio>
#include <cstdlib>

int compare(const void*a,const void *b)
{
    return (*(int*)a - *(int*)b);
}
int main()
{
    int *x=(int*)malloc(sizeof(int)*1000000);
    int t,i;
    scanf("%d",&t);
    for(i=0;i<t;i++)
        scanf("%d",&x[i]);
    qsort(x,t,sizeof(int),compare);
    for(i=0;i<t;i++)
        printf("%d\n",x[i]);
    return 0;
}
