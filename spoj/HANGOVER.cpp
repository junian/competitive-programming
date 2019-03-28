#include<cstdio>

int main()
{
    int m[521];
    double i,r;
    int n=1,a;
    char x[5];
    r=0.50f;
    for(a=1;a<=520;a++)
    {
        i=a/100.0f;
        if(i>r)
        {
            while(i>r)
            {
                n++;
                r+=(1.0f/(n+1));
            }
        }
        m[a]=n;
    }
    while(1)
    {
        scanf("%s", x);
        a=(x[0]-'0')*100 + (x[2]-'0')*10 + (x[3]-'0');
        if(a==0)
            break;
        printf("%d card(s)\n",m[a]);
    }
    return 0;
}
