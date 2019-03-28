#include <cstdio>
#define INF 9999999
#define min(a,b) a<b?a:b;
int main()
{
    char C[128][128];
    int step[128][128];
    int t,m,n;
    scanf("%d\n",&t);
    while(t--){
        
        scanf("%d%d\n", &m, &n);
        for(int i=0;i<m;i++)
            scanf("%s", C[i]);
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                step[i][j] = INF;
        step[0][0] = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(C[i][j]!='#'){
                    if(i+1<m && C[i+1][j]!='#')
                        step[i+1][j] = min(step[i][j]+1, step[i+1][j]);
                    if(j+1<n && C[i][j+1]!='#')
                        step[i][j+1] = min(step[i][j]+1, step[i][j+1]);
                    int b = C[i][j]-'0';
                    if(i+1+b<m && C[i+1+b][j]!='#')
                        step[i+1+b][j] = min(step[i][j]+1, step[i+1+b][j]);
                    if(j+1+b<n && C[i][j+1+b]!='#')
                        step[i][j+1+b] = min(step[i][j]+1, step[i][j+1+b]);
                }
            }
        }
        /*for(int i=0;i<m;i++){
            for(int j=0;j<n;j++)
                printf("%d ", step[i][j]);
            puts("");
            }*/
        if(step[m-1][n-1] == INF)
            puts("-1");
        else
            printf("%d\n", step[m-1][n-1]);
    }
    return 0;
}
