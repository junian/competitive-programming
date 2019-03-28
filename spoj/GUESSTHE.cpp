#include <cstdio>

long long gcd(long long a, long long b)
{
    if(a == 0)
        return b;
    while (b != 0)
    {
        if(a>b)
            a=a-b;
        else
            b=b-a;
    }
    return a;
}

long long lcs(long long a, long long b)
{
    return (a*b)/gcd(a,b);
}

int main()
{
    char x[21];
    int y[20];
    int n[20];
    int yy,nn,i;
    long long lc;
    bool tr;
    while(1)
    {
        scanf("%s",x);
        if(x[0]=='*')
            break;
        yy=0;
        nn=0;
        for(i=0;x[i]!='\0';i++)
        {
            if(x[i]=='Y')
                y[yy++]=i+1;
            else
                n[nn++]=i+1;
        }
        tr=false;
        if(nn>0 && n[0]!=1 || nn==0)
        {
            lc=y[0];
            for(i=1;i<yy;i++)
                lc=lcs(lc,y[i]);
            tr=true;
            for(i=0;i<nn;i++)
                if(lc%n[i]==0)
                {
                    tr=false;
                    break;
                }
        }
        if(tr)
            printf("%lld\n",lc);
        else
            printf("-1\n");
    }
    return 0;
}
