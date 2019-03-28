#include <cstdio>
#include <cstring>
int main()
{
    char d[1024];
    int a,n,i;
    while(1)
    {
        scanf("%s",d);
        if(d[0]=='0' && d[1]=='\0')
            break;
        a=0;
        n=strlen(d);
        for(i=0;i<n;i+=2)
            a+=(d[i]-'0');
        for(i=1;i<n;i+=2)
            a-=(d[i]-'0');
        if(a%11==0)
            printf("%s is a multiple of 11.\n",d);
        else
            printf("%s is not a multiple of 11.\n",d);
    }
    return 0;
}
