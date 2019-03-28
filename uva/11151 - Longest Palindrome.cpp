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
    int m, n, t;

    c = (int**) malloc(sizeof(int*) * 1002);
    for(int i=0; i<1002; i++)
        c[i] = (int*) malloc(sizeof(int) * 1002);

    fflush(stdin);
    scanf("%d", &t);

    while(t>0)
    {
        t--;
        fflush(stdin);
        gets(s1);
//        strupper(s1);
        m = strlen(s1);
        n = m;
        s2[n] = '\0';
        for(int i=0; i<n; i++)
        {
            s2[i] = s1[n-i-1];
        }
        for(int i=0; i<=m; i++)
            c[i][0] = 0;
        for(int i=0; i<=n; i++)
            c[0][i] = 0;
        for(int i=1; i<=m; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if(s1[i-1] == s2[j-1])
                {
                    c[i][j] = c[i-1][j-1] + 1;
                }
                else
                    c[i][j] = max(c[i-1][j], c[i][j-1]);
            }
        }

        //if(n>0)
            printf("%d\n", c[m][n]);
        //else
            //printf("1\n");
    }

    for(int i=0; i<1002; i++)
        free(c[i]);
    free(c);

    return 0;
}
