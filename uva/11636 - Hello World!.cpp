#include <cstdio>
int main()
{
    int n[10001];
    int i,j,k=1;
    n[0]=n[1]=0;
    for(i=2;i<10001;i*=2)
    {
        n[i]=k++;
        for(j=i/2+1;j<i;j++)
            n[j]=n[i];
    }
    i/=2;
    for(j=i+1;j<10001;j++)
        n[j]=n[i]+1;
    k=0;
    while(1)
    {
        scanf("%d",&i);
        if(i<0)
            break;
        k++;
        printf("Case %d: %d\n",k,n[i]);
    }
    return 0;
}
