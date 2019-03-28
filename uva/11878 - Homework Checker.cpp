#include<cstdio>
#include<cstdlib>
int main()
{
    long a,b,n,t=0;
    char s[100],c;
    while(scanf("%ld%c%ld=%s",&a,&c,&b,s)!=EOF)
    {
        if(s[0]!='?')
        {
            n=strtol(s,NULL,10);
            if(c=='+' && a+b==n)
                t++;
            else if(c=='-' && a-b==n)
                t++;
        }
    }
    printf("%ld\n",t);
    return 0;
}
