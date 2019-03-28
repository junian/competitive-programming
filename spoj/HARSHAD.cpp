#include <cstdio>
#include <cstdlib>
#include <cstring>

#define MAX 1000000
#define AKR 1000

int primes[7000];
int notPrime[500002];
int x=0;

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


int sod(int n)
{
    int tmp=n;
    int sodn = 0;
    while(tmp>0)
    {
        int dig = tmp%10;
        sodn += dig;
        tmp=tmp/10;
    }
    return sodn;
}

int isSelf(int n)
{
    int drn = ((n-1)%9)+1;//(sod(n)%9==0)?9:sod(n)%9;
    int drsn = (drn%2==0)?drn>>1:(drn+9)>>1;
    int dn = 0;
    int tmp = n;
    while(tmp>0)
    {
        dn++;
        tmp/=10;
    }
    
    for(int i=0;i<=dn;i++)
    {
        int tmp = (n-drsn-9*i);
        //printf("%d %d %d %d %d\n",drn, drsn, tmp, sod(tmp), tmp + sod(tmp));
        if(tmp + sod(tmp) == n)
            return 0;
    }
    
    return 1;
}

void sieve()
{
//    notPrime = (bool*)malloc(sizeof(bool)*(MAX+1)>>1);
    int i,j,k;
    for(i=3;i<=AKR;i+=2)
    {
        //printf("%d %d, ", i, notPrime[i>>1]);
        if(!notPrime[i>>1])
        {
            //printf("%d ", i);
            //primes[x++]=i;
            for(j=i*i,k=2*i;j<=MAX;j+=k)
                notPrime[j>>1]=1;
        }
    }
    //puts("aaa");
    for(i=3;i<=MAX;i+=2)
    {
        if(!notPrime[i>>1] && isSelf(i))
        {
            primes[x++]=i;
            //printf("   %d\n", i);
        }
    }
    //puts("");
}

int main()
{
    sieve();
    int t;
    int a,b;
//    scanf("%d",&t);
    t=getNum();
    while(t--)
    {
        a = getNum();
        b = getNum();
        //scanf("%d%d",&a,&b);
        //int total = 0;
        int i=0;
        int lo, hi;
        lo = 0; hi = x;
        while(lo<hi)
        {
            int mid = (lo+hi)/2;
            if(primes[mid]<a)
                lo = mid+1;
            else
                hi = mid;
        }
        int low = lo;
        lo = low; hi = x;
        while(lo<hi)
        {
            int mid = (lo+hi)/2;
            if(primes[mid]<b)
                lo = mid+1;
            else
                hi = mid;
        }
        int high = primes[hi]==b?hi:hi-1;
        printf("%d\n", high-low+1);
        /*
        for(i=0;i<x;i++)
            if(primes[i] >= a)
                break;
        for(i=i;primes[i]<=b && i<x;i++)
            total++;*/
        //printf("%d\n", total);
    }
    return 0;
}
