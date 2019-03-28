#include <cstdio>

#define MAX 10000

int tree[MAX+32][MAX+32];

int main()
{
    int n,i,x,y;
    scanf("%d",&n);
    for(i=0;i<n-1;i++)
    {
        scanf("%d%d",&x,&y);
        tree[x][y] = tree[y][x] = 1;
    }
    return 0;
}
