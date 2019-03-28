#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

typedef struct Gajah
{
    int x;
    int w;
    int iq;
};

int compare_w( const void* a, const void* b )
{
    Gajah* x = (Gajah*) a;
    Gajah* y = (Gajah*) b;

    if( (*x).w < (*y).w )
        return -1;
    else if( (*x).w == (*y).w )
    {
        if( (*x).iq == (*y).iq )
            return 0;
        else if( (*x).iq < (*y).iq )
            return -1;
        else
            return 1;
    }
    else
        return 1;
}

int compare_iq( const void* a, const void* b )
{
    Gajah* x = (Gajah*) a;
    Gajah* y = (Gajah*) b;

    if( (*x).iq > (*y).iq )
        return -1;
    else if( (*x).iq == (*y).iq )
    {
        if( (*x).w == (*y).w )
            return 0;
        else if( (*x).w > (*y).w )
            return -1;
        else
            return 1;
    }
    else
        return 1;
}

void bt(int **c, Gajah a[1000], Gajah b[1000], int i, int j, int res[1000], int n)
{
    if(i == 0 or j == 0)
        return;
    if(a[i-1].x == b[j-1].x)
    {
        res[n] = a[i-1].x;
        bt(c, a, b, i-1, j-1, res, n-1);
    }
    else if(c[i][j-1] > c[i-1][j])
        bt(c, a, b, i, j-1, res, n);
    else
        bt(c, a, b, i-1, j, res, n);

}

int main()
{
    Gajah a[1000];
    Gajah b[1000];

    int **c;
    int i, j;
    int x, y, n=0;
    int res[1000];

    c = (int**) malloc(sizeof(int*) * 1001);
    for(i = 0; i<1001; i++)
        c[i] = (int*) malloc(sizeof(int) * 1001);

    while(scanf("%d %d", &x, &y) != EOF)
    {
        a[n].w = b[n].w = x;
        a[n].iq = b[n].iq = y;
        a[n].x = b[n].x = n+1;
        n++;
    }

    qsort(a, n, sizeof(Gajah), compare_w);
    qsort(b, n, sizeof(Gajah), compare_iq);

    for(i=0; i<=n; i++)
        c[i][0] = c[0][i] = 0;

    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
        {
            if(a[i-1].x == b[j-1].x)
                c[i][j] = c[i-1][j-1] + 1;
            else
                c[i][j] = max(c[i-1][j], c[i][j-1]);
        }
    }

    printf("%d\n", c[n][n]);
    bt(c, a, b, n, n, res, c[n][n]-1);
    for(i=0; i<c[n][n]; i++)
        printf("%d\n", res[i]);

    return 0;
}
