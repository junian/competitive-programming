#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

void bt(int d[32][32], char a[31][101], char b[31][101], int i, int j, int x, char res[31][101])
{
    if(i == 0 or j == 0)
        return;
    else if(strcmp(a[i-1], b[j-1]) == 0)
    {
        strcpy(res[x], a[i-1]);
        bt(d, a, b, i-1, j-1, x-1, res);
    }
    else if (d[i][j-1] > d[i-1][j])
        bt(d, a, b, i, j-1, x, res);
    else
        bt(d, a, b, i-1, j, x, res);
}

int main()
{
    char a[31][101];
    char b[31][101];
    char res[31][101];

    char c[101];
    int d[32][32];

    int i, j;

    while(1)
    {
        i = j = 0;
        while(1)
        {
            if(scanf("%s", c) == EOF)
                return 0;
            if(strcmp(c, "#") == 0)
                break;
            strcpy(a[i++], c);
        }
        while(1)
        {
            scanf("%s", c);
            if(strcmp(c, "#") == 0)
                break;
            strcpy(b[j++], c);
        }

        for(int x=0; x<=i; x++)
            d[x][0] = 0;
        for(int x=0; x<=j; x++)
            d[0][x] = 0;
        for(int x=1; x<=i; x++)
        {
            for(int y=1; y<=j; y++)
            {
                if(strcmp(a[x-1], b[y-1]) == 0)
                    d[x][y] = d[x-1][y-1] + 1;
                else
                    d[x][y] = max(d[x-1][y], d[x][y-1]);
            }
        }

        bt(d, a, b, i, j, d[i][j]-1, res);

        for(int x=0; x<d[i][j]-1; x++)
            printf("%s ", res[x]);
        if(d[i][j] == 0)
            break;
        else
            printf("%s\n", res[d[i][j]-1]);

    }

    return 0;
}
