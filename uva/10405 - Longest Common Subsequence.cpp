#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main()
{
    char s1[1001];
    char s2[1001];
    int **c;
    int m, n;

    c = (int**) malloc(sizeof(int*) * 1002);
    for(int i=0; i<1002; i++)
        c[i] = (int*) malloc(sizeof(int) * 1002);

    while(gets(s1) != NULL)
    {
        gets(s2);
        m = strlen(s1);
        n = strlen(s2);

        for(int i=0; i<=m; i++)
            c[i][0] = 0;
        for(int i=0; i<=n; i++)
            c[0][i] = 0;
        for(int i=1; i<=m; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if(s1[i-1] == s2[j-1])
                    c[i][j] = c[i-1][j-1] + 1;
                else
                    c[i][j] = max(c[i][j-1], c[i-1][j]);
            }
        }
        printf("%d\n", c[m][n]);
    }

    for(int i=0; i<1002; i++)
        free(c[i]);
    free(c);

    return 0;
}
