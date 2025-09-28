#include <cstdio>
#define N 9

int sudoku_grid[N][N];

int find_min_in_row(int row)
{
    int min = N+1;
    for(int i=0;i<N;i++)
        min = (grid[row][i]<min)?grid[row][i]:min;
    return min;
}

int find_min_in_col(int col)
{
    int min = N+1;
    for(int i=0;i<col;i++)
        min = (grid[i][col]<min)?grid[i][col]:min;
    for(int i=row+1;i<N;i++)
        min = (grid[row][i]<min)?grid[row][i]:min;
    return min;
}

int main()
{
    return 0;
}
