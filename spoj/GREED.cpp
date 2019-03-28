#include <cstdio>
#include <climits>
#include <algorithm>

using namespace std;

#define MAX 500


typedef struct koin{
    int a,b;
};

int INFINITE = 1000;
int path[MAX+1][MAX+1];
int coins[MAX+1];
koin tes[MAX+1];
bool ok[MAX+1];


bool cmp(koin a, koin b)
{
    return a.b<b.b;
}

int main()
{
    int t,n,e,i,j,k,a,b;
    long long num;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(i=1;i<=n;i++)
            scanf("%d",&coins[i]);

        scanf("%d",&e);

        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                path[i][j] = INFINITE;

//        for(i=1;i<=n;i++)
//        {
//            for(j=1;j<=n;j++)
//                printf("%d ", path[i][j]);
//            puts("");
//        }
        for(i=1;i<=n;i++)
            path[i][i] = 0,ok[i]=false;
//        for(i=1;i<=n;i++)
//        {
//            for(j=1;j<=n;j++)
//                printf("%d ", path[i][j]);
//            puts("");
//        }
        for(i=0;i<e;i++)
        {
            scanf("%d%d",&a,&b);
            path[a][b] = path[b][a] = 1;
        }
//        for(i=1;i<=n;i++)
//        {
//            for(j=1;j<=n;j++)
//                printf("%d ", path[i][j]);
//            puts("");
//        }
        for(k=1;k<=n;k++)
            for(i=1;i<=n;i++)
                for(j=1;j<=n;j++)
                    path[i][j] = min(path[i][j],path[i][k]+path[k][j]);

//        for(i=1;i<=n;i++)
//        {
//            for(j=1;j<=n;j++)
//                printf("%d ", path[i][j]);
//            puts("");
//        }
        num = 0;

        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                tes[j].a = j;
                tes[j].b = path[coins[i]][j];
                //printf("%d\n",path[coins[i]][j]);
            }
            sort(tes+1,tes+n+1,cmp);
//            for(j=1;j<=n;j++)
//                printf("++ %d ",tes[j].b);
//            puts("");
            for(j=1;j<=n;j++)
            {
//                printf("%d %d - %d\n",i,coins[i],tes[j].b);
                if(!ok[tes[j].a])
                {
                    ok[tes[j].a] = true;
//                    printf(" --%d %d - %d\n",i,coins[i],tes[j].b);
                    num += tes[j].b;
                    break;
                }
            }
        }

        printf("%lld\n",num);
    }
    return 0;
}
