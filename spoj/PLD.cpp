#include <cstdio>
#include <cstring>
bool palin(char *a, char *b)
{
    while(a<b)
    {
        if(*a!=*b)
            return false;
        a++;
        b--;
    }
    return true;
}
int main()
{
    char s[30001];
    int t,i,k,x;
    while(scanf("%d",&k)!=EOF)
    {
        scanf("%s",s);
        t=strlen(s);
        x=0;
        for(i=0;i+k-1<t;i++)
            if(palin(&s[i],&s[i+k-1]))
                x++;
        printf("%d\n",x);
    }
    return 0;
}
