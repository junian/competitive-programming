#include <cstdio>

#define WATER '.'
#define LAND  '#'
#define VISIT 'x'

void visit(char island[200][201],int i, int j)
{
    if(island[i][j]!=LAND)
        return;
    island[i][j]=VISIT;
    visit(island,i,j-1);
    visit(island,i-1,j);
    visit(island,i,j+1);
    visit(island,i+1,j);
    visit(island,i+1,j-1);
    visit(island,i-1,j-1);
    visit(island,i-1,j+1);
    visit(island,i+1,j+1);
}
int main()
{
    int t,x,y,i,j,z;
    char island[200][201];
    scanf("%d",&t);
    while(t-->0)
    {
        scanf("%d%d",&x,&y);
        for(i=0;i<x;i++)
            scanf("%s",island[i]);
        z=0;
        for(i=1;i<x-1;i++)
        {
            for(j=1;j<y-1;j++)
            {
                if(island[i][j]==LAND)
                {
                    z++;
                    visit(island,i,j);
                }
            }
        }
        printf("%d\n",z);
    }
    return 0;
}
