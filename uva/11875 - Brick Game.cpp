#include <cstdio>
#include <algorithm>

using namespace std;

int T, N;
int A[100];

int main()
{
    scanf("%d", &T);
    for(int tc = 1;tc<=T;tc++)
    {
        scanf("%d", &N);
        for(int i=0;i<N;i++)
        {
            scanf("%d", &A[i]);
        }
        sort(A, A+N);
        printf("Case %d: %d\n", tc, A[N>>1]);
    }
    return 0;
}
