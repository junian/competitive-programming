#include <cstdio>
int main()
{
    char x;
    long long a,t=0,n,c;
    while((x=getchar())!='\n')
        t=t*10+(x-'0');
    while(t--)
    {
        n=0;
        while((x=getchar()),!(x>='0' && x<='9'));
        n=x-'0';
        while((x=getchar()),(x>='0' && x<='9'))
            n=n*10+(x-'0');
        c=x;
        a=0;
        while(1)
        {
            x=getchar();
            if(x>='0'&&x<='9')
                a=a*10+(x-'0');
            else if(x=='+' || x=='-' || x=='*' || x=='/' || x=='=')
            {
                if(c=='+')
                    n+=a;
                else if(c=='-')
                    n-=a;
                else if(c=='*')
                    n*=a;
                else if(c=='/')
                    n/=a;
                a=0;
                c=x;
            }
            else if(x=='\n')
                break;
        }
        printf("%lld\n",n);
    }
    return 0;
}
