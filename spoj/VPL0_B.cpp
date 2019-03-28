#include <cstdio>
#include <algorithm>

using namespace std;

int data[1001][10001];
int cnt[1001];
int main()
{
    int T,N,U,s;
    scanf("%d", &T);
    for(int tc=1;tc<=T;tc++)
    {
        scanf("%d%d",&N,&U);
        for(int i=0;i<=U;i++)
            cnt[i] = 0;
        //int max = 0;
        while(N--)
        {
            scanf("%d", &s);
            int mod = s % U;
            int div = s / U;
            data[div][cnt[div]++] = mod;
            //if(div>max)
//                max = div;
        }
        //int len = 1;
//        while(max>9)
//        {
//            len++;
//            max/=10;
//        }
        printf("Scenario #%d:\n\n", tc);
        for(int i=0;i<=U;i++)
        {
            if(cnt[i]!=0)    
            {
                printf("%d |", i);
                sort(data[i], data[i]+cnt[i]);
                for(int j=0;j<cnt[i];j++)
                    printf(" %d", data[i][j]);
                puts("");
            }
        }
        puts("");
    }
    return 0;
}
