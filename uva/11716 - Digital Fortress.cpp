#include <cstdio>

int main()
{
    int a[10001];
    int i,j,n=0,k,l;
    char x;
    char m[10001];
    char s[102][102];
    for(i=0;i<=10000;i++)
        a[i]=-1;
    for(i=0;i<=100;i++)
        a[i*i]=i;
    while((x=getchar())!='\n')
        n = n*10 + (x-'0');
    while(n--)
    {
        k=0;
        while((x=getchar())!='\n')
            m[k++]=x;
        if(a[k]<0)
            printf("INVALID\n");
        else
        {
            l=0;
            for(i=0;i<a[k];i++)
                for(j=0;j<a[k];j++)
                    s[i][j]=m[l++];
            for(i=0;i<a[k];i++)
                for(j=0;j<a[k];j++)
                    putchar(s[j][i]);
            printf("\n");
        }
    }
    return 0;
}
