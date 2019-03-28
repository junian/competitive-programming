#include <cstdio>
#include <cstring>

int main()
{
    char a[15],b[15];
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s %s",a,b);
        if(strstr(a,b)!=NULL)
            printf("1\n");
        else
            printf("0\n");
    }
    return 0;
}
