#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
    int b1[101];
    int b2[101];
    int c[102][102];

    int n1, n2, t=1, i, j;

    while(1)
    {
        scanf("%d %d", &n1, &n2);
        if(n1 == 0 && n2 ==0 )
            break;
        //if(t != 1)
            //printf("\n");

        for(i=0; i<n1; i++)
            scanf("%d", &b1[i]);
        for(i=0; i<n2; i++)
            scanf("%d", &b2[i]);

        for(i=0; i<=n1; i++)
            c[i][0] = 0;
        for(i=0; i<=n2; i++)
            c[0][i] = 0;

        for(i=1; i<=n1; i++)
        {
            for(j=1; j<=n2; j++)
            {
                if(b1[i-1] == b2[j-1])
                    c[i][j] = c[i-1][j-1] + 1;
                else
                    c[i][j] = max(c[i-1][j], c[i][j-1]);
            }
        }

        printf("Twin Towers #%d\n", t);
        printf("Number of Tiles : %d\n", c[n1][n2]);
        printf("\n");
        t++;
    }

    return 0;
}
