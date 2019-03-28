#include <stdio.h>
#include <ctype.h>

char line[11111];
int lptr, parameter;
char command;

void get_parameter()
{
     int sign=1;
     if(line[lptr]=='+') lptr++;
     else if(line[lptr]=='-') { sign=-1; lptr++; }
     parameter=0;
     while(isdigit(line[lptr])) parameter=10*parameter+line[lptr++]-'0';
     parameter*=sign;
}

void get_command()
{
     char dir;
     
     for(;line[lptr];lptr++) if((line[lptr]=='^')||(line[lptr]=='@')) break;
     if(!line[lptr]){ command='Q'; return; }
     if(line[lptr]=='^')
     {
        command='2'; lptr++;
        get_parameter();
        return;
     }
     dir=line[++lptr];
     lptr++;
     get_parameter();
     switch(dir)
     {
        case 'N': command='Y'; parameter*=-1; break;
        case 'S': command='Y'; break;  
        case 'W': command='X'; parameter*=-1; break;
        case 'E': command='X'; break;
     }
}

int main()
{
    int cases;
    int x,y,z,xx,yy,zz;
    int from,to;
    int level[256][256];
    int volume;
    
    fgets(line,sizeof(line),stdin);
    sscanf(line,"%d",&cases);
    while(cases--)
    {
       fgets(line,sizeof(line),stdin);
       lptr=0;
       for(x=0;x<250;x++) for(y=0;y<250;y++) level[x][y]=0;
       x=y=0; z=-1;
       while(1)
       {
          get_command();
          if(command=='Q') break;
          if(command=='X')
          {
             xx=x+parameter;
             if(xx>x){ from=x+1; to=xx; }
             else { from=xx; to=x-1; }
             if(from<0) from=0;
             if(to>=250) to=249;
             for(x=from;x<=to;x++) if(z>level[x][y]) level[x][y]=z;
             x=xx;
          }
          else if(command=='Y')
          {
             yy=y+parameter;
             if(yy>y){ from=y+1; to=yy; }
             else { from=yy; to=y-1; }
             if(from<0) from=0;
             if(to>=250) to=249;
             for(y=from;y<=to;y++) if(z>level[x][y]) level[x][y]=z;
             y=yy;
          }
          else if(command=='2')
          {
             z+=parameter;
             if(level[x][y]<z) level[x][x]=z;
          }
       }
       volume=0;
       for(x=0;x<250;x++) for(y=0;y<250;y++) volume+=level[x][y];
       printf("%d\n",volume);
    }
    return 0;
}
