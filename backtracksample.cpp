#include <cstdio>

char maze[100][100];

bool trace(int i, int j)
{
    if(maze[i][j] == 'F')
        return true;
    if(maze[i][j] == '#')
        return false;
    if(maze[i][j] == '.')
        return false;
    maze[i][j] = '.';

    trace(i-1,j);
    trace(i,j+1);
    trace(i+1,j);
    trace(i,j-1);

}

int main()
{
    return 0;
}
