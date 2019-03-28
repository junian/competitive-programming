#include <cstdio>
#include <queue>

using namespace std;

#define MAX 832

char maze[MAX][MAX];

int m,n;
void bfs(int a, int b, int mm[MAX][MAX])
{
    queue< pair<int, int> > q;
    mm[a][b] = 1;
    q.push(make_pair(a,b));
    while(!q.empty())
    {
        //puts("aa");
        pair<int,int> v = q.front();
        int x=v.first;
        int y=v.second;
        q.pop();
        //printf("%d %d\n",x,y);
        if(x-1>=0 && maze[x-1][y]!='#' && mm[x-1][y]==0)
        {
            q.push(make_pair(x-1,y));
            mm[x-1][y] = mm[x][y]+1;
        }
        
        if(x+1<m && maze[x+1][y]!='#' && mm[x+1][y]==0)
        {
            q.push(make_pair(x+1,y));
            mm[x+1][y] = mm[x][y]+1;
        }
        
        if(y-1>=0 && maze[x][y-1]!='#' && mm[x][y-1]==0)
        {
            q.push(make_pair(x,y-1));
            mm[x][y-1] = mm[x][y]+1;
        }
        if(y+1<n && maze[x][y+1]!='#' && mm[x][y+1]==0)
        {
            q.push(make_pair(x,y+1));
            mm[x][y+1] = mm[x][y]+1;
        }
    }
}
int mm[3][MAX][MAX];
int main()
{
    int t;
    
    scanf("%d", &t);
    while(t--)
    {        
        scanf("%d %d\n", &m, &n);
                    
        
        n+=400,m+=400;
        for(int i=0;i<m;i++)
                for(int j=0;j<n;j++)
                    maze[i][j]='.';
        for(int aa=0;aa<3;aa++)
            for(int i=0;i<m;i++)
                for(int j=0;j<n;j++)
                    mm[aa][i][j]=0;
        for(int i=200;i<m-200;i++)
        {
            //for(int j=200;j<n-200;j++)
                //maze[i][j]=getchar();
            gets(&maze[i][200]);
            maze[i][m-200]='.';
        }
        
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(maze[i][j]>='1' && maze[i][j]<='3')
                {
                    //printf("%c\n", maze[i][j]);
                    bfs(i,j,mm[maze[i][j]-'0'-1]);
                }
            }
        }
        /*
        for(int aa=0;aa<3;aa++)
        {
            for(int i=0;i<m;i++)
            {
                for(int j=0;j<n;j++)
                    printf("%d ", mm[aa][i][j]);
                puts("");
            }
            puts("");
        }*/
        
        int mini=2147483640;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(maze[i][j]!='#')
                    mini = min(mini, max(mm[0][i][j], max(mm[1][i][j],mm[2][i][j])));
            }
        }
        printf("%d\n",mini-1);
    }
    return 0;
}
