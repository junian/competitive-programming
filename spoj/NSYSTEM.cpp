#include <cstdio>
#include <cstring>
#include <cstdlib>
int toInt(char *a)
{
    int n=1,c=0;
    while(*a!='\0')
    {
        switch(*a)
        {
            case 'm':
                c+=(n*1000);
                n=1;
                break;
            case 'c':
                c+=(n*100);
                n=1;
                break;
            case 'x':
                c+=(n*10);
                n=1;
                break;
            case 'i':
                c+=n;
                n=1;
                break;
            default:
                n = (*a)-'0';
                break;
        }
        a++;
    }
    return c;
}

int main()
{
    int t,a,b,c,i;
    char l[4][2] = {"m","c","x","i"};
    char x[10],y[10],r[10];
    char z[2];
    scanf("%d",&t);
    while(t-->0)
    {
        scanf("%s %s", x, y);
        a=toInt(&x[0]);
        b=toInt(&y[0]);
        //printf("%d %d\n",a,b);
        c=a+b;
        strcpy(r,"");
        b=0;
        for(i=1000;i>=1;i/=10)
        {
            a=c/i;
            if(a>0)
            {
                if(a>1)
                {
                    z[0]=a+'0';
                    z[1]='\0';
                    strcat(r,z);
                }
                strcat(r,l[b]);
                c=c%i;
            }
            b++;
        }
        printf("%s\n", r);
    }
    return 0;
}
