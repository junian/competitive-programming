#include <cstdio>

int main()
{
    long long int x,y;
    char s[1000];
    
    while(1)
    {
        int two_input = 0;
        int i=0;
        while(1)
        {
            s[i]=getchar_unlocked();            
            if(s[i]==EOF || s[i++]=='\n') break;
        }
        s[i-1] = '\0';
        x=0;
        y=0;
        
        i=0;
        while(!(s[i]>='0' && s[i]<='9'))
            i++;
            
        for(i=i;s[i]!='\0' && two_input==0;i++)
        {
            if(s[i] == ' ')
            {
                two_input = 1;
                break;
            }
            x = x*10 + (s[i]-'0');
        }
        
        if(two_input)
        {
            for(i++;s[i]!='\0';i++)
            {
                if(s[i]>='0' && s[i]<='9')
                    y = y*10 + (s[i]-'0');
            }
        }
        
        //two_input = scanf("%d %d\n", &x, &y);
        
        if(x == 0 && y == 0)
            break;
        
        if(two_input)
        {   
            x -= 2;
            y -= 1;
            
            //long long int a = x/23;
            //long long int b = y/23;
            
            long long int ac = x % 23;
            long long int bc = y % 23;
            long long int yx = y-x;
            //long long int yx1 = y-x+1;
            //long long int dtg = 23-(y-x+3);
           // printf("%lld %lld %lld %lld\n", x,y,ac, bc);
            //if((ac!=0 && bc!=0) || x<0 || y<0)
            //if((ac==0 && !(bc>=0 && bc<23) && !(yx)) || (bc==0 && !(ac>=0 && ac<23)) || (ac!=0 && bc!=0) || x<0 || y<0)
            if((ac==0 && bc!=0 && !(yx>=0 && yx<23)) || 
               (bc==0 && ac!=0 && !(yx>0 && yx<=23)) || 
               (ac==0 && bc==0 && !(yx==0 || yx==23)) || 
               (ac!=0 && bc!=0) || x<0 || y<0)
                puts("No Number");
            /*
            else if(ac>0 || (ac==0 && bc==0 && y>0))
            {
                //long long int ri =  (x-ac)*2+1+ac;
                long long int up = (y-23)*2+1+ac;
                printf("%lld\n", up+23);
            }
            else
            {
                long long int ri = x*2+1+bc;
                //long long int up = (y-bc)*2+1+bc;
                printf("%lld\n", ri);
            }*/
            else
                printf("%lld\n", x+y+1);
        }
        else
        {
            x--;
            long long int a = x/23;
            long long int b = x%23;
            //long long int up = a-(a>>1); //+ (a%2==1?1:0);
            //up += (a%2==1?1:0);
            long long int ri = a>>1;
            long long int up = a-ri;
            //prlong long intf("%d %d %d %d\n", a, a%2, up, ri);
            long long int xx = ri*23+2;
            long long int yy = up*23+1;
            if(a&1==1)
                xx+=b;
            else
                yy+=b;
            printf("%lld, %lld\n", xx, yy);
        }
        
    }
    return 0;
}
