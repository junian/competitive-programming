#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int main()
{
    char a[7],b[7];
    char x;
    int n=0,i;
    while((x=getchar())!='\n')
        n=n*10+(x-'0');
    a[6]='\0';
    b[6]='\0';
    while(n--)
    {
        i=0;
        while((x=getchar())!='\n')
            if(x!=' ')
                a[i++]=x;
        i=0;
        while((x=getchar())!='\n')
            if(x!=' ')
                b[i++]=x;
        sort(a,a+6);
    }
    if(strcmp(a,b)==0)
            puts("Twin snowflakes found.");
        else
            puts("No two snowflakes are alike.");
    return 0;
}
