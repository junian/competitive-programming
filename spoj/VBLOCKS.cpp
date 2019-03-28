#include <cstdio>

#define MAXI 100032

using namespace std;

int l,s,d,a,b,k;
int block[MAXI];
int dp[MAXI];

int main()
{
    
    scanf("%d %d %d", &l, &s, &d);
    scanf("%d", &k);
    while(k--)
    {
        scanf("%d %d", &a, &b);
        block[a] = b;
    }
    int count=0;
    int step=0;
    bool ff = true;
    for(int i=1;i<=l;i++)
    {
        dp[i] = dp[i-1];
        if(ff)
        {
            if(block[i] == 2)
            {
                count = 0;
                //dp[i] = dp[i-1];
            }
            else if(count == s-1)
            {
               // printf("%d\n", i);
                ff=!ff;
                dp[i]++;
                count = 0;
            }
            else
            {
                count++;
            }
        }
        else
        {
            if(block[i] == 1)
            {
                step = 0;
                //dp[i] = dp[i-1];
            }
            else if(step == d-1)
            {
                ff=!ff;
                //dp[i]=dp[i-1]+1;
                step = 0;
            }
            else
                step++;
        }
    }
    for(int i=1;i<=l;i++)
        printf("%d ", dp[i]);
    puts("");
    printf("%d\n", dp[l]);
    while(1);
    return 0;
}
