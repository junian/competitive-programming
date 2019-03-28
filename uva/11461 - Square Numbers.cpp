#include <cstdio>
int main()
{
    int s[100001];

    int i,a,b,c;
    for(i=0;i<=100000;i++)
        s[i]=0;
    for(i=0;i<317;i++)
        s[i*i]=1;
    while(1)
    {
        scanf("%d%d",&a,&b);
        if(a==0 && b==0)
            break;
        c=0;
        for(i=a;i<=b;i++)
            c+=s[i];
        printf("%d\n",c);
    }
    return 0;
}
