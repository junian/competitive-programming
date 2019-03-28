#include <cstdio>
#include <algorithm>

using namespace std;

int getNum(){
    int res=0;
    char c;
    int b=0;
    
    while (1){
     c=getchar_unlocked();
        if(c=='-') b=1;
        if(c==' ' || c=='\n') continue;
        else break;
        
        }
        
        if (c!= '-') res= c - '0';
        while (1){
            c=getchar_unlocked();
            if(c>='0' && c <= '9') res = 10* res + c - '0';
            else break;
            
            }
            
            if (b == 1) res *= -1;
            return res;
}

int main()
{
    int n,k,p,x;
    n=getNum();
    k=getNum();
    while(k--)
    {
        p=getNum();
        x=getNum();
        if(p==1)
        {
            int gcd = __gcd(n, x);
            n = n/gcd;
        }
        printf("%d\n", n);
    }
    return 0;
}
