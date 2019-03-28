#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

char *substract(char *a, char *b)
{
    char *c = new char[256];
    int carry = 0,x,y;
    int na = strlen(a)-1;
    int nb = strlen(b)-1;
    int nc = na+1;
    c[nc--] = '\0';
    while(na>=0 || nb>=0)
    {
        x = a[na]-'0';
        if(nb>=0)
            y = b[nb]-'0'+carry;
        else
            y = carry;
        if(x < y)
        {
            c[nc--] = (10+x-y)+'0';
            carry = 1;
        }
        else
        {
            c[nc--] = (x-y)+'0';
            carry = 0;
        }
        na--;
        nb--;
    }
    return c;
}

char *add(char *a, char *b)
{
    char *c = new char[256];
    int carry = 0,x,y,z;
    int na = strlen(a)-1;
    int nb = strlen(b)-1;
    int nc = max(na,nb)+2;
    c[nc--] = '\0';
    while(na>=0 || nb>=0)
    {
        if(na>=0)
            x = a[na]-'0';
        else
            x = 0;
        if(nb>=0)
            y = b[nb]-'0';
        else
            y = 0;
        z = x+y+carry;
        carry = z/10;
        c[nc--] = (z%10)+'0';
        na--;
        nb--;
    }
    c[0] = carry + '0';
    return c;
}

char *remleadzero(char *a)
{
    char *zero = "0";
    int i,j;
    int n = strlen(a);
    char *d = new char[n+1];
    for(i=0;i<n;i++)
        if(a[i]!='0')
            break;
    if(i>=n)
        return zero;
    int x=0;
    for(j=i;j<n;j++)
        d[x++] = a[j];
    d[x] = '\0';
    return d;
}

int main()
{
    int t;
    char b[256],c[256],d[256];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s%s%s",b,c,d);
        puts(remleadzero(add(substract(c,b),substract(c,d))));
    }

    return 0;
}
