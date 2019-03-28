#include <cstdio>
#include <cstdlib>

#define MAX 86028121
#define LIM MAX/2+1

bool *prime = (bool*)malloc(sizeof(bool)*LIM);
int p[5000000];

bool isPrime(int x)
{
    if(x<2)
        return false;
    if(x==2)
        return true;
    if(x%2==0)
        return false;
    return !prime[(x-3)/2];
}
int main()
{
    register int i,j,k=0,l;
    p[k++]=2;
    for(i=3;i*i<=MAX;i+=2)
    {
        if(isPrime(i))
        {
            for(j=i*i,l=2*i;j<=MAX;j+=l)
                prime[(j-3)/2]=true;
        }
    }
    for(i=3;i<=MAX;i+=2)
        if(isPrime(i))
            p[k++]=i;
    scanf("%d",&i);
    while(i--)
    {
        scanf("%d",&j);
        printf("%d\n",p[j-1]);
    }
    return 0;
}
