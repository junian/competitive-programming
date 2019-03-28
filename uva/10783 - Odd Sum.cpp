#include <cstdio>
int main()
{
    int t,a,b,c,i;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%d%d",&a,&b);
        if(a%2==0)a++;
        c=0;
        while(a<=b)
        {
            c+=a;
            a+=2;
        }
        printf("Case %d: %d\n",i,c);
    }
    return 0;
}
