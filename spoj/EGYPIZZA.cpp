#include <cstdio>

#define min(a,b)    a<b?a:b

int main()
{
    int n,a=0,b=0,c=0,d,e,t=1;
    char x[4];
    scanf("%d",&n);
    while(n-->0)
    {
        scanf("%s",x);
        d=x[0]+x[2]-2*'0';
        switch(d)
        {
            case 3:
                a++;
                break;
            case 5:
                b++;
                break;
            default:
                c++;
                break;
        }
    }
    e=min(b,c);
    t += e;
    b-=e;
    c-=e;
    t += a/2;
    a=a%2;
    t += b/4;
    b=b%4;
    if(a==1)
    {
        if(b>=2)
            t++;
        else if(b==1)
            t++;
        else
            t++;
    }
    else if(b>0)
        t++;
    t += c;
    printf("%d\n",t);
    return 0;
}
