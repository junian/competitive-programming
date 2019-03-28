#include <cstdio>
#include <cstring>

int main()
{
    char s[1024];
    char *c = s;
    while(scanf("%s",c)!=EOF)
    {
        printf("%d\n",strlen(s));
        c = &s[strlen(s)];
    }
    int max = 0;
    int tmp;
    printf("%d\n",strlen(s));
    for(int i=0;i<strlen(s)-5;i++)
    {
        tmp = 1;
        for(int j=i;j<i+5;j++)
        {
            tmp = tmp * (s[j]-'0');
        }
        if(tmp>max)
            max = tmp;
    }
    printf("%d\n",max);
}

