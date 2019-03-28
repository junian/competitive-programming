#include <cstdio>

int main()
{
    long long doll[2002];
    long long n, init,i,x=0,j;
    scanf("%lld%lld",&n,&init);
    for(i=0;i<n;i++)
        scanf("%lld",&doll[i]);
    for(i=0;i<n-1;i++)
    {
        if(doll[i+1]>doll[i])
        {
            for(j=i+2;j<n;j++)
            {
                if(doll[j]<doll[j-1])
                    break;
            }
            j--;

        }
    }
    return 0;
}
