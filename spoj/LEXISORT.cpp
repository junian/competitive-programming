#include <cstdio>
#include <cstdlib>
#include <cstring>

int compare(const void*a,const void *b)
{
    char**x=(char**)a;
    char**y=(char**)b;
    return (strcmp(*x,*y));
}
int main()
{
    char **x=(char**)malloc(sizeof(char*)*50000);
    int t,i,n;
    for(i=0;i<50000;i++)
        x[i]=(char*)malloc(sizeof(char)*11);
    scanf("%d",&t);
    while(t-->0)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%s",x[i]);
        qsort(x,n,sizeof(char*),compare);
        for(i=0;i<n;i++)
            printf("%s\n",x[i]);
    }
    return 0;
}
