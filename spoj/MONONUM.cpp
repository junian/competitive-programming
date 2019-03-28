#include <cstdio>
#include <iostream>

using namespace std;

#define LD long double

LD fact8 = 40320.0L;
LD fact9 = 362880.0L;

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

LD inc(int x)
{
    LD n = x+8;
    return n*(n-1)*(n-2)*(n-3)*(n-4)*(n-5)*(n-6)*(n-7)/fact8;
}

LD dec(int x)
{
    LD n = x+1;
    return n*(n+1)*(n+2)*(n+3)*(n+4)*(n+5)*(n+6)*(n+7)*(n+8)/fact9-1;
}

int main()
{
    int t,n;
    //scanf("%d", &t);
    t=getNum();
    while(t--)
    {
        //scanf("%d", &n);
        n=getNum();
        //cout << dec(n)/inc(n);
        printf("%.6LF\n", dec(n)/inc(n));
    }
}
