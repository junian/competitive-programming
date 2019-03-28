#include <cstdio>

int main()
{
    char a[500000],b[500000];
    int x,y;
    while(scanf("%s%s",a,b)!=EOF)
    {
        x=0;y=0;
        while(a[x]!='\0' && b[y]!='\0')
        {
            if(a[x] == b[y])
                x++;
            y++;
        }
        if(a[x]=='\0')
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
