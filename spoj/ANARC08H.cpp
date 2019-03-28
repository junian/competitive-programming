#include <cstdio>
#include <cstdlib>
//int josephus(int n, int k)
//{
//    if(n == 1)
//        return 0;
//    return (josephus(n-1, k) + k) % n;
//}
int main()
{
    int *josh=(int*)malloc(sizeof(int)*1000001);
    int n,d,i;
    josh[1]=0;
    while(1)
    {
        scanf("%d%d",&n,&d);
        if(n<=0 && d<=0)
            break;
        for(i=2;i<=n;i++)
            josh[i]=(josh[i-1]+d)%i;
        printf("%d %d %d\n",n,d,josh[n]+1);
    }

    return 0;
}
