#include <cstdio>
#include <cstdlib>
#include <cstring>

#define MAX 3400
#define SEG 100000
#define AKR 31623

long long primes[MAX];
bool *notPrime;
bool *seg;
int seg_size=(SEG/2)+1;

void sieve()
{
    notPrime = (bool*)malloc(sizeof(bool)*(AKR+1)>>1);
    seg = (bool*)malloc(sizeof(bool)*seg_size);
    int i,j,k,x=0;
    for(i=3;i<=AKR;i+=2)
    {
        if(!notPrime[i/2])
        {
            primes[x++]=i;
            for(j=i*i,k=2*i;j<=AKR;j+=k)
                notPrime[j/2]=true;
        }
    }
}

void segment_sieve(long long a, long long b)
{
    memset(seg,false,sizeof(bool)*seg_size);
    long long j,k,i;
    for(i=0; primes[i]*primes[i]<=b; i++)
    {
        j = primes[i] * ( (a+primes[i]-1) / primes[i] );
        if(j%2==0) j += primes[i];
        for(k=primes[i]<<1; j<=b; j+=k)
            if(j!=primes[i])
                seg[(j-a)>>1]=true;
    }
}

int main()
{
    sieve();
    int t;
    long long a,b,i;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld%lld",&a,&b);
        if(a<3)
        {
            if(a<=2)
                printf("2\n");
            a=3;
        }
        else if(a%2==0)
            a++;
        segment_sieve(a,b);
        for(i=a;i<=b;i+=2)
            if(!seg[(i-a)>>1])
                printf("%lld\n",i);
        if(t)
            printf("\n");
    }
    return 0;
}
