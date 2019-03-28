#include <cstdio>
#include <cmath>
//#include <algorithm>
//#define ll long long
//#define max(a,b) a>b?a:b
//using namespace std;
long long int kor[10005][5];
long long int MAX = 1000000000000000000LL;
int main()
{
    int t;
    int n=4;
    while(1)
    {
        for(int i=0;i<n;i++)
            for(int j=0;j<5;j++)
                kor[i][j] = 0;
        kor[0][2] = -1;
        kor[n>>1][0] = -1;
        kor[n>>1][2] = -1;
        kor[n>>1][4] = -1;
        kor[n-1][2] = -1;
//        printf("%lld\n", kor[0][2]);
        kor[0][0] = 1L;
//        printf("%lld\n", kor[0][0]);
        int i;
        for(i=1;i<n && kor[i][0]!=-1;i++)
        {
            kor[i][0] = 1L;
        }
        for(;i<n;i++)
            kor[i][0] = 0L;
        for(i=1;i<5 && kor[0][i]!=-1;i++)
        {
            kor[0][i] = 1L;
        }
        for(;i<4;i++)
            kor[0][i] = 0L;
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<5;j++)
                if(kor[i][j]!=-1L){
                    //kor[i][j] = max(0L,kor[i-1][j])+max(0L,kor[i][j-1]);//+max(0,kor[i-1][j-1]);
                    long long int a = 0L;
                    if(kor[i-1][j]!=-1)
                        a = kor[i-1][j];
                    long long int b = 0L;
                    if(kor[i][j-1]!=-1)
                        b = kor[i][j-1];
                    long long int c = 0L;
                    if(kor[i-1][j-1]!=-1)
                        c = kor[i-1][j-1];
                    kor[i][j] = a+b+c;
                    //printf("%I64d\n", kor[i][j]);
                }
                    
        }
        //printf("%.0f\n", log10(kor[n-1][4]));
        printf("%d. %lld\n", n, kor[n-1][4]);
        if(n>=10)
        {
            //printf("%d. %lld\n", n, kor[n-1][4]);
            break;
        }
        n++;
    }
    scanf("%d", &t);
    return 0;
}
