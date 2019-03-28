#include<cstdio>

using namespace std;

int T,N,F,Q,I,J,E,S,M;
char C[5];
char A[1024];
int mapstate[101][256][101];
bool dp[101][2];
int count[101][256];
bool finalstate[101];
int inits;
    
int main()
{
    
    scanf("%d", &T);
    for(int tc=1;tc<=T;tc++)
    {
        scanf("%d%d%d%d", &N, &M, &F, &Q);
        
        for(int i=0;i<=N;i++)
            finalstate[i] = false;
            
        for(int i=0;i<F;i++){
            scanf("%d", &E);
            finalstate[E] = true;
        }
        
        for(int i=0;i<=N;i++)
            for(int j=0;j<256;j++)
                count[i][j] = 0;
                
        for(int i=0;i<M;i++)
        {
            scanf("%d%d", &I, &J);
            scanf("%s", C);
            int cnt = count[I][C[0]]++;
            mapstate[I][C[0]][cnt] = J; 
        }
        
        printf("Scenario #%d:\n", tc);
        scanf("%d", &S);
        
        //printf("%d\n", S);
        while(S--)
        {
            scanf("%s",A);
            for(int i=0;i<=N;i++){
                dp[i][0] = dp[i][1] = false;
            }
            
            int c = 0;
            dp[Q][0] = true;
            for(c=0;A[c]!='\0';c++)
            {
                int prev = c&1;
                int now = (c+1)&1;
                for(int i=0;i<=N;i++)
                {
                    if(dp[i][prev])
                    {
                        dp[i][prev] = false;
                        for(int j=0;j<count[j][A[c]];j++)
                        {
                            dp[mapstate[j][A[c]][j]][now] = true;
                        }
                    }
                }
            }
            
            bool accepted = false;
            int now = c&1;
            for(int i=0;i<=N && !accepted;i++)
                if(dp[i][now] && finalstate[i])
                    accepted = true;
            printf("%s ", A);
            if(accepted)
                puts("Accepted");
            else
                puts("Rejected");
        }
        
    }
    return 0;
}
