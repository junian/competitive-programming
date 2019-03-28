#include <cstdio>

using namespace std;

int main()
{
    int tot[1001] = {0};
    int num[2600];
    int last = 0;
    int n;

    tot[0] = 1;
    num[0] = 1;
    num[1] = 1;
    for(int i=1; i<=1000; i++)
    {
        for(int j=0; j<=last; j++)
        {
            num[j] *= i;
        }
        for(int j=0; j<last; j++)
        {
            num[j+1] += num[j]/10;
            num[j] = num[j]%10;
        }
        while(num[last]>=10)
        {
            num[last+1] = num[last]/10;
            num[last] = num[last]%10;
            last++;
        }
        tot[i] = 0;
        for(int j=0; j<=last; j++)
            tot[i] += num[j];
    }

    while(scanf("%d", &n)!=EOF)
    {
        printf("%d\n", tot[n]);
    }

    return 0;
}
