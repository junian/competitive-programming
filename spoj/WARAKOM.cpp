#include <cstdio>
#define max(a,b) a>b?a:b
int t,m,q,n;
int a[64];
bool dp[64][1024];
int maxi = -1;

template<typename T>
T getNum()
{
      	  T res = 0;   
  		  char c;
  		  while(1)
  		  {
		   		  c=getchar_unlocked();
		   		  if(c==' ' || c=='\n')continue;
		   		  else break;
  		  }
  		  res= c - '0';
  		  while(1)
  		  {
		   		  c = getchar_unlocked();
		   		  if(c>='0' && c<='9')res=10*res + c-'0';
		   		  else break;
  		  }
  		  return res;
}

void sum(int s, int i)
{
    if(i==n){
        if(maxi<s){
            maxi = s;
        }
        return;
    }
    int count = s + a[i];
    if(count<=m){
        if(!dp[i+1][count])
            sum(count, i+1);
        dp[i][s] = true;
    }
    count = s - a[i];
    if(count>=0){
        if(!dp[i+1][count])
            sum(count, i+1);
        dp[i][s]=true;
    }
}

int main()
{
    
    //scanf("%d", &t);
    t = getNum<int>();
    while(t--)
    {
        //scanf("%d%d%d", &n, &q, &m);
        n = getNum<int>();
        q = getNum<int>();
        m = getNum<int>();
        for(int i=0;i<n;i++)
            //scanf("%d", &a[i]);
            a[i] = getNum<int>();
        maxi = -1;
        
        for(int i=0;i<=n;i++)
            for(int j=0;j<=1000;j++)
                dp[i][j] = false;
        //sum(q,0);
        int count = a[0] + q;
        if(count <= m)
            dp[0][count] = true;
        count = q-a[0];
        if(count >=0 )
            dp[0][count] = true;
        
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<=m;j++)
            {
                if(dp[i-1][j])
                {
                    count = a[i] + j;
                    if(count <= m)
                        dp[i][count] = true;
                    count = j-a[i];
                    if(count >= 0)
                        dp[i][count] = true;
                }   
                
            }
        }
        maxi=-1;
        for(int j=0;j<=m;j++){
            if(dp[n-1][j]){
                maxi = max(maxi, j);
            }
        }
        printf("%d\n", maxi);
        
    }
    return 0;
}

