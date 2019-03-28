#include <cstdio>
#include <cstdlib>
int main()
{
    char *isPrime=(char*)malloc(sizeof(char)*100010042);
    long long i,j,n;
    for(i=3;i*i<100010042;i+=2)
    {
        isPrime[i]=1;
    }
    for(i=3;i*i<100010042;i+=2)
    {
        if(isPrime[i]==1)
        {
            for(j=2*i;j<100010042;j+=i)
                isPrime[j]=0;
        }
    }
    for(i=1423;i<=2222;i++)
    {
        n=i*i+i+41;
        if(isPrime[n]==0 || n%2==0)
            printf("0,");
        else
            printf("1,");
    }
//    int a,b;
//    int tot=0;
//    while(scanf("%d%d",&a,&b)!=EOF)
//    {
//        tot=b-a+1;
//    }
    return 0;
}
