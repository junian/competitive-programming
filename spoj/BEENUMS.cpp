#include <cstdio>
#include <cstdlib>

int compare(const void*a,const void*b)
{
    return (*(int*)a - *(int*)b);
}

int main()
{
    long long b[18258];
    long long i;
    int*p;
    b[0]=1;
    for(i=1;i<18258;i++)
    {
        b[i] = b[i-1]+6*i;
    }
//    for(i=1;i<10;i++)
//        printf("%lld\n",b[i]);
    while(1)
    {
        scanf("%lld",&i);
        if(i==-1)
            break;
        p=(int*)bsearch(&i,b,18258,sizeof(long long),compare);
        if(p==NULL)
            printf("N\n");
        else
            printf("Y\n");
    }
    return 0;
}
