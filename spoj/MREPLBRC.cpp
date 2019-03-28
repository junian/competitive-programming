#include <cstdio>

#define ll long long int
#define MAX 256
#define MOD 100000

int dp[MAX][MAX];
char str[MAX];
int isMod;
int N;

//int getNum()
//{
//    int res = 0;
//    char c;
//    int b = 0;
//    while(1)
//    {
//       c=getchar_unlocked();
//       if(c=='-') b=1;
//       if(c==' ' || c=='\n')continue;
//       else break;
//    }
//    if(c!='-')res=c-'0';
//    while(1)
//    {
//       c=getchar_unlocked();
//       if(c >= '0' && c<= '9') res=10*res+c-'0';
//       else break;
//    }
//    if(b==1) res *= -1;
//    return res;
//}

int val(char a, char b){
    if (((a == '(' || a == '[' || a == '{') && b == '?')
         || (a == '?' && (b == ']' || b == '}' || b == ')'))
         || (a == '(' && b == ')') || (a == '{' && b == '}') || (a == '[' && b == ']'))
         return 1;
    if(a == '?' && b=='?')
        return 3;
    return 0;
}
int iter = 0;
ll count(int l, int r){
    printf("%d,%d ",l,r);
    iter++;
    if(l>r)
        return 1;
    if(dp[l][r]!=-1)
        return dp[l][r];
     ll res = 0;
     for(int i=l+1;i<=r;i+=2)
     {
         int l = 
        res += val(str[l], str[i]) * count(l+1, i-1) * count(i+1, r);
     }
     if(res > MOD)
     {
        isMod = 1;
        res = res % MOD;
     }
     dp[l][r] = res;
     return res;
}

int main(){
    scanf("%d%s", &N, str);
    /*N = getNum();
    char c = getchar_unlocked();
    while(c==' ' || c=='\n' || c=='\r')
        c = getchar_unlocked();
    str[0] = c;
    for(int i=1;i<N;i++)
       str[i] = getchar_unlocked();*/
    //scanf("%s",str);
    isMod = 0;
    for(int j=0;j<N;j++){
        for(int i=j+1;i<N;i++)
            dp[i][j] = 1;
        for(int i=0;i<=j;i++)
            dp[i][j] = -1;
        dp[j][j]=0;
    }
    for(int i=0;i<N-1;i++)    
        dp[i][i+1] = val(str[i], str[i+1]);
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++)
            printf("%2d ", dp[i][j]);
            puts("");
        }
        puts("");
    
   for(int j=N-4;j>=0;j-=2){
        for(int i=0;i<=j;i++){
            int l=i;
            int r = i+N-j-1;
            for(int m=l+1;m<=r;m+=2)
                dp[l][r] = dp[l][r] + val(str[l], str[m]) * dp[l+1][m-1] * dp[m+1][r];
            printf("%2d,%2d:%2d,%2d,%2d ",l,r,val(str[l], str[r]),dp[l+1][r-1],dp[r+1][r]);
        }
        puts("");
    }



    //for(int i=0;i<N;i++)
//        for(int j=0;j<N;j++)
//            count(i,j);
    ll res = dp[0][N-1];//count(0, N-1);
    puts("");
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++)
            printf("%2d ", dp[i][j]);
            puts("");
        }
    if(isMod)
        printf("%05lld\n", res);
    else
        printf("%lld\n", res);    
        printf("%d\n", iter);
    while(1);
    return 0;
}
