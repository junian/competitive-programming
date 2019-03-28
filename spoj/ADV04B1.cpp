#include <cstdio>

#define MAX 1000000
#define M   1000003LL
//#define MM  1000001


//long long steps;
//
//void trace(int i, int j, int max)
//{
//    if(i==max && j==max)
//    {
//        steps++;
//        return;
//    }
//    if(i>max || j>max)
//        return;
//    trace(i+1,j,max);
//    trace(i,j+1,max);
//    trace(i+1,j+1,max);
//}

//long long power(long long a, int b)
//{
//    if(b==0)
//        return 1;
//    if(a==0)
//        return 0;
//    if(b%2==0)
//        return power((a*a)%M,b/2)%M;
//    return (a*(power((a*a)%M,b/2)%M))%M;
//}

long long inv(long long x) {
    long long a = 1, b = x, c;
    while (b != 1) {
        c = M / b;
        a *= c; a %= M;
        b *= c; b %= M;
        if (b > M/2) { a = M - a; b = M - b; }
    }
    return a;
}
//long long gcd(long long a, long long b)
//{
//    if (b==0)
//       return a;
//    else
//       return gcd(b, a % b);
//}

long long d[MAX+1];

int main()
{
//    inXt i;
//    for(int i=1;i<=10;i++)
//    {
//        steps = 0;
//        trace(1,1,i);
//        printf("%lld\n",steps);
//    }
    int t,i,x,y;


    d[0]=1;
    d[1]=3;
    d[2]=13;
    d[3]=63;
    for(i=4;i<=MAX;i++)
    {
        //d[i]= ((((3*(2*i-1)*d[i-1])%M) + (M - (((i-1)*d[i-2])%M)))%M) / i ;
        //d[i]= (((((3*(2*i-1)*d[i-1])) + (M - (((i-1)*d[i-2])%M)))%M) * (power(i,MM)))%M ;
        d[i]= (((((3*(2*i-1)*d[i-1])) + (M - (((i-1)*d[i-2])%M)))%M) * (inv(i)%M))%M ;
    }
//    for(i=0;i*i<=MAX;i++)
//        printf("%lld,",d[i]);
//    puts("a");
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&i);
        printf("%lld\n",d[i-1]);
    }
    return 0;
}
