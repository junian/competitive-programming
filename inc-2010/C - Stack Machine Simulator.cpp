#include <cstdio>

void reverse(char *a, char *b)
{
    char c;
    while(a<b)
    {
        c = *a;
        *a=*b;
        *b=c;
        a++;
        b--;
    }
}

int main()
{
    char stack[128];
    char x;
    int t=0,i,n;
    while((x=getchar())!='\n')
    {
        t=t*10+(x-'0');
    }
    while(t--)
    {
        n=0;
        while((x=getchar())!='\n')
        {
            if(x=='^' && n>0)
                reverse(&stack[0],&stack[n-1]);
            if(x=='+')
                stack[n++] = getchar();
        }
        stack[n]='\0';
        puts(stack);
    }
    return 0;
}
