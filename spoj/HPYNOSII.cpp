#include<cstdio>

int tb[1001] = {0};

int happy(long long n)
{
    if(n/10 == 0)
        if(n==1)
            return 0;
        else if(n==7)
            return 5;
        else
            return -1;
    int t=0,s=0,x=0;
    if(n>1000)
    {
        while(n>0)
        {
            t+=(n%10)*(n%10);
            n=n/10;
        }
        n=t;
        t=0;
        s++;
    }
    if(tb[n]!=0)
        return tb[n];
    x=n;
    while(n>0)
    {
        t+=(n%10)*(n%10);
        n=n/10;
    }
    s++;
    t=happy(t);
    if(t==-1)
        tb[x] = t;
    else
        tb[x] = s+t;
    return tb[x];
}

int main()
{
    long long n,t=0,c=0,a;
    //tb[0]=tb[2]=tb[3]=tb[4]=tb[5]=tb[6]=tb[9]=-1;
    //tb[1]=0;
    //tb[7]=5;
    scanf("%lld",&a);
    while(a--)
    {
        scanf("%lld",&n);
//        while(1)
//        {
//            if(n/10==0 && n!=7)
//                break;
//            while(n>0)
//            {
//                t+=(n%10)*(n%10);
//                n=n/10;
//            }
//            printf("%d ",t);
//            n=t;
//            t=0;
//            c++;
//        }
//        if(n%10!=1)
//            puts("-1");
//        else
//            printf("%lld\n",c);
        printf("%d\n",happy(n));
    }
    return 0;
}

