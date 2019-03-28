#include <cstdio>
#include <cstring>

#define R 32
#define C 128

#define STEP '#'
#define SPACE ' '

char maze[R][C];

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

void dfs(int i, int j)
{
    maze[i][j] = STEP;
    for(int a=0;a<4;a++)
    {
        int t1 = i+dx[a];
        int t2 = j+dy[a];
        if(maze[t1][t2]==SPACE)
            dfs(t1,t2);
    }
}

int main()
{
    int t,i,n,a,b;
    scanf("%d\n",&t);
    bool found;
    while(t--)
    {
        found = false;
        n=0;
        while(true)
        {
            gets(maze[n]);
            if(!found)
                for(int c = 0; maze[n][c]!='\0'; c++)
                {
                    if(maze[n][c]=='*')
                    {
                        a = n;
                        b = c;
                        found = true;
                        break;
                    }
                }
            if(maze[n++][0]=='_')
                break;
        }
        if(found)
            dfs(a,b);
        for(i=0;i<n;i++)
            puts(maze[i]);
    }
    return 0;
}
