#include <cstdio>

using namespace std;

#define MOD 1000000007
#define lli long long int

lli getNum(){
    lli res=0;
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

lli f(lli n)
{
    if(n<0)
        return 0;
    return ((n+2)*(n+1));
}

int main()
{
    lli t;
    lli N,minA,maxA,minB,maxB,minC,maxC;
    //scanf("%d", &t);
    t=getNum();
    while(t--)
    {
        //scanf("%lld", &N);
        //scanf("%lld %lld", &minA, &maxA);
        //scanf("%lld %lld", &minB, &maxB);
        //scanf("%lld %lld", &minC, &maxC);
        N=getNum();
        minA=getNum();
        maxA=getNum();
        minB=getNum();
        maxB=getNum();
        minC=getNum();
        maxC=getNum();
        lli res = 0;
        
        lli limmax = N-maxA-maxB-maxC;
        lli limmin = N-minA-minB-minC;
        
        if(limmax <= 0 && limmin >= 0)
        {
            //printf("aaa\n");
            maxA -= minA;
            maxB -= minB;
            maxC -= minC;
 
            lli A = maxA;
            lli B = maxB;
            lli C = maxC;
 
            N = limmin;
            //N -= (minA + minB + minC);
        
            res = (f(N)-f(N-A-1)-f(N-B-1)-f(N-C-1)+f(N-A-B-2)+f(N-C-B-2)+f(N-A-C-2)-f(N-A-B-C-3))>>1;
        }
        
        printf("%lld\n",res%MOD);
    }
    return 0;
}
