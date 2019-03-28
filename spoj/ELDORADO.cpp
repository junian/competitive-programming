#include <cstdio>
#include <algorithm>

int main()
{
    int a[100];
    int c[101][101];
    long long res;
    int k, n, i, j;

    while(1)
    {
        scanf("%d %d", &k, &n);
        if(k==0 && n==0)
            break;
        for(i=0; i<k; i++)
        {
            scanf("%d", &a[i]);
        }
        res = 0;
        for(i=0; i<k; i++)
        {
            for(j=0; j<k; j++)
            {
                if(a[i] == a[j])
                {
                    c[i][j] = 0;
                }
//                else if(a[i][j])
            }
        }

    }

    return 0;
}
