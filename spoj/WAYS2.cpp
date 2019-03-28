#include <stdio.h>

char maze[16][16];
int val[16][16];
int m,n;
int targetr, targetc;

void dp()
{
    int i,j;
    val[0][0] = 1;
    for(i=1;maze[i][0]!='@' && i<m;i++)
        val[i][0]=1;
    for(i=i; i<m;i++)
        val[i][0]=0;
    
    for(i=1;maze[0][i]!='@' && i<n;i++)
        val[0][i]=1;
    for(i=i;i<n;i++)
        val[0][i]=0;
        
    for(i=1;i<m;i++)
        for(j=1;j<n;j++)
        {
            if(maze[i][j]=='@')
                val[i][j]=0;
            else
                val[i][j]=val[i-1][j-1]+val[i][j-1]+val[i-1][j];
        }        
        
}

/*void solve(int r, int c)
{
    if(r<0 || c<0 || r>=m || c>=n)
        return;
    if(maze[r][c] == '@')
        return;

    val[r][c]++;
    
    solve(r+1,c);
    solve(r+1,c+1);
    solve(r,c+1);
}*/

int main()
{
    scanf("%d %d", &m, &n);
    int i;
    for(i=0;i<m;i++)
        scanf("%s\n", maze[i]);
    
    scanf("%d", &i);
    //solve(0,0);
    dp();
    while(i--)
    {
        scanf("%d %d", &targetr, &targetc);
        printf("%d\n", val[targetr][targetc]);
        /*if((targetr<0 || targetc<0 || targetr>=m || targetc>=n) ||
            maze[targetr][targetc] == '@')
            puts("0");
        else
        {
            printf("%d\n", val[targetr][targetc]);
        }*/
    }
    return 0;
    
}

