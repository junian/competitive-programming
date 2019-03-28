#include <cstdio>
int main()
{
    int i,x=0,y=0,c=0,d=0;
    char a[32],b[32];
    scanf("%s %s",a,b);
    for(i=0;a[i]!='\0';i++)
    {
        if(a[i]=='6' || a[i]=='5')
        {
            x = x*10+5;
            c = c*10+6;
        }
        else
        {
            x = x*10+(a[i]-'0');
            c = c*10+(a[i]-'0');
        }
    }
    for(i=0;b[i]!='\0';i++)
    {
        if(b[i]=='6' || b[i]=='5')
        {
            y = y*10+5;
            d = d*10+6;
        }
        else
        {
            y = y*10+(b[i]-'0');
            d = d*10+(b[i]-'0');
        }
    }
    printf("%d %d\n",x+y,c+d);
    return 0;
}
