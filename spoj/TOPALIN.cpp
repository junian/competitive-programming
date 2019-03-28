#include <cstdio>
#include <cstring>

using namespace std;
 
char s[100032];
int dp[150];
int count[150];
 
int find(int i)
{
    if(dp[i] == i) return i;
    return dp[i] = find(dp[i]);
}
 
int main()
{
    while(scanf("%s", s)!=EOF){
        int len = strlen(s);
        for(int i=0;i<150;i++)
            count[i] = 0;
        for(int i = 0 ; i < len ; i++)
        {
            count[s[i]]++;
            dp[s[i]] = s[i];
        }
        int h = len>>1;
        int cost = 0;
        for(int i = 0 ; i < h ; i++)
        {
            int left = find(s[i]);
            int right = find(s[len - i - 1]);
            
            if(left != right)
            {
                if(count[left] <= count[right])
                {
                    dp[left] = right;
                    cost += count[left];
                }
                else
                {
                    dp[right] = left;
                    cost += count[right];
                }
            }
        }
        
        printf("%d\n",cost);
    }
    return 0;
}
