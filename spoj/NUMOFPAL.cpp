#include <cstdio>
#include <cstring>

bool pal(char *a, char*b)
{
    while(a<b)
    {
        if(*a != *b)
            return false;
        a++;
        b--;
    }
    return true;
}

int main()
{
    char s[1024];
    int n,i,j,p;
    while(scanf("%s",s)!=EOF)
    {
        n=strlen(s);
        p=n;
        for(i=1;i<n;i++)
        {
            for(j=0;j+i<n;j++)
                if(pal(&s[j],&s[j+i]))
                    p++;
        }
        printf("%d\n",p);
    }
    return 0;
}
