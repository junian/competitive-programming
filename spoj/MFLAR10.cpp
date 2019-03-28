#include <cstdio>

char tolower(char x)
{
    if(x>='A' && x<='Z')
        return (x-'A')+'a';
    return x;
}

int main()
{
    char x,k;
    bool tau;
    while(1)
    {
        k=getchar();
        if(k=='*')
            break;
        k=tolower(k);
        tau=true;
        while((x=getchar())!='\n')
        {
            if(x==' ')
                if(k!=tolower(getchar()))
                    tau=false;
        }
        if(tau)
            puts("Y");
        else
            puts("N");
    }
    return 0;
}
