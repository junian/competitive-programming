#include <cstdio>
#include <cstring>

int main()
{
    int n=0,i,j;
    bool space;
    char a[25],b[25];
    char x;
    while((x=getchar())!='\n')
        n = n*10 + (x-'0');
    for(i=1;i<=n;i++)
    {
        space=false;
        j=0;
        fflush(stdin);
        while((x=getchar())!='\n')
        {
            if(x==' ')
                space=true;
            else
                a[j++]=x;
        }
        a[j]='\0';
        j=0;
        while((x=getchar())!='\n')
            b[j++]=x;
        b[j]='\0';
        j=strcmp(a,b);
        printf("Case %d: ",i);
        if(j==0)
        {
            if(!space)
                printf("Yes\n");
            else
                printf("Output Format Error\n");
        }
        else
            printf("Wrong Answer\n");
    }
    return 0;
}
