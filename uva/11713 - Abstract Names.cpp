#include <cstdio>
#include <cstring>

bool isnotvowel(char x)
{
    return (x!='a' && x!='i' && x!='u' && x!='e' && x!='o');
}

int main()
{
    char a[25],b[25];
    char x;
    int n=0,la,lb,i;
    while((x=getchar())!='\n')
        n=n*10+(x-'0');
    while(n--)
    {
        la=lb=0;
        i=0;
        while((x=getchar())!='\n')
        {
            la++;
            if(isnotvowel(x))
                a[i++]=x;
        }
        a[i]='\0';
        i=0;
        while((x=getchar())!='\n')
        {
            lb++;
            if(isnotvowel(x))
                b[i++]=x;
        }
        b[i]='\0';
        if(la==lb && strcmp(a,b)==0)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
