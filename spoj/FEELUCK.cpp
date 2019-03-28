#include <cstdio>

#define MAX 128

int main()
{
    char link[11][MAX];
    int pts[11];
    int t;
    scanf("%d",&t);
    int i,j;
    for( i=1;i<=t;i++)
    {
        int maxx = 0;
        for( j=0;j<10;j++)
        {
            scanf("%s %d",link[j],&pts[j]);
            if(pts[j] > maxx)
                maxx = pts[j];
        }
        printf("Case #%d:\n", i);
        for(j=0;j<10;j++)
            if(pts[j] == maxx)
                puts(link[j]);
    }  
    return 0;
}
