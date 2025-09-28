#include <stdio.h>

int board[7][8];

void read_input()
{
     int r,c;
     for(r=0;r<7;r++) for(c=0;c<8;c++) scanf("%d",&board[r][c]);
}

int count_ways(int level)
{
    static int covered[7][8];
    static int used[7][7];
    int row,col;
    int i,j;
    int result=0;
    
    if(level==0)
    {
       for(row=0;row<7;row++) for(col=0;col<8;col++) covered[row][col]=0;
       for(i=0;i<7;i++)for(j=0;j<7;j++) used[i][j]=0;
    }
    if(level==56) return 1;
    row=level/8;
    col=level%8;
    i=board[row][col];
    if(covered[row][col]) return count_ways(level+1);
    if((col<7)&&!covered[row][col+1]&&!used[i][j=board[row][col+1]])
    {
       covered[row][col]=covered[row][col+1]=1;
       used[i][j]=used[j][i]=1;
       result+=count_ways(level+1);
       used[i][j]=used[j][i]=0;
       covered[row][col]=covered[row][col+1]=0;
    }
    if((row<6)&&!covered[row+1][col]&&!used[i][j=board[row+1][col]])
    {
       covered[row][col]=covered[row+1][col]=1;
       used[i][j]=used[j][i]=1;
       result+=count_ways(level+1);
       used[i][j]=used[j][i]=0;
       covered[row][col]=covered[row+1][col]=0;
    }
    return result;
}

int main()
{
    int cases;
    
    scanf("%d",&cases);
    while(cases--)
    {
       read_input();
       printf("%d\n",count_ways(0));
    }
    return 0;
}                                                             
