#include <cstdio>
#include <cstdlib>
#include <ctime>

#define WALL    1
#define SPACE   0

#define X       0
#define Y       1

#define UP      0
#define RIGHT   1
#define DOWN    2
#define LEFT    3

int direction[4][2]={{-1,0},{0,1},{1,0},{0,-1}};

typedef struct Vector2D
{
    int x;
    int y;
};

void generateMaze(char **maze, int length, int width, Vector2D pos)
{
    int n=rand()%4;
    int i=4;
    maze[pos.x][pos.y] = SPACE;
    Vector2D newPos;
    while(i-->0)
    {
        newPos.x = pos.x+2*direction[n][X];
        newPos.y = pos.y+2*direction[n][Y];
        if(newPos.x>=0 && newPos.x<length &&
           newPos.y>=0 && newPos.y<width &&
           maze[ newPos.x ][ newPos.y ] == WALL)
        {
            maze[ pos.x+direction[n][X] ][ pos.y+direction[n][Y] ] = SPACE;
            generateMaze(maze, length, width, newPos);
        }

        n = (n+1)%4;
    }

}

int main()
{
    int x,y,m,n,i,j,a,b;
    Vector2D pos;
    char **maze;
    srand(time(NULL));
    while(scanf("%d%d",&x,&y)!=EOF)
    {
        m=2*x+1;
        n=2*y+1;

        maze = new char*[m];
        for(i=0;i<m;i++)
            maze[i] = new char[n];

        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
                maze[i][j]=WALL;
        }
//        for(i=1;i<m;i+=2)
//        {
//            for(j=0;j<n;j+=2)
//                maze[i][j]=WALL;
//            for(j=1;j<n;j+=2)
//                maze[i][j]=SPACE;
//        }

        pos.x=2*(rand()%x)+1;
        pos.y=2*(rand()%y)+1;

        generateMaze(maze, m, n, pos);

        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                switch(maze[i][j])
                {
                    case SPACE:
                        printf(" ");
                        break;
                    default:
                        printf("#");
                        break;
                }
            }
            printf("\n");
        }

        for(i=0;i<m;i++)
            delete []maze[i];
        delete []maze;
    }
    return 0;
}
