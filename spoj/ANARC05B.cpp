#include <cstdio>
#include <cstdlib>
#define max(a,b)    a>b?a:b
#define min(a,b)    a<b?a:b

int *res,*a,*b,*d,*e;

int compare(const void *a, const void *b)
{
    return (*(int*)a - *(int*)b);
}

int main()
{
    int i,j,k,l,m,n,t,tota,totb;
    int *s;
    a=(int*)malloc(sizeof(int)*10000);
    b=(int*)malloc(sizeof(int)*10000);
    res=(int*)malloc(sizeof(int)*10000);
    while(1)
    {
        scanf("%d",&n);
        if(n==0)
            break;
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        scanf("%d",&m);
        for(i=0;i<m;i++)
            scanf("%d",&b[i]);
        l=0;
        if(n<m)
        {
            j=n;k=m;
            d=a;e=b;
        }
        else
        {
            j=m;k=n;
            d=b;e=a;
        }
        for(i=0;i<j;i++)
        {
            s=(int*)bsearch(&d[i],e,k,sizeof(int),compare);
            if(s!=NULL)
            {
                //k=k-(s-e);
                //e=s+1;
                res[l++]=*s;
            }
        }
        j=0;
        k=0;
        t=0;
        for(i=0;i<l;i++)
        {
            tota=0;
            while(a[j]!=res[i])
            {
                tota+=a[j];
                j++;
            }
            tota+=a[j];
            j++;
            totb=0;
            while(b[k]!=res[i])
            {
                totb+=b[k];
                k++;
            }
            totb+=b[k];
            k++;
            t+=max(tota,totb);
        }
        tota=0;
        while(j<n)
        {
            tota+=a[j];
            j++;
        }
        totb=0;
        while(k<m)
        {
            totb+=b[k];
            k++;
        }
        t+=max(tota,totb);
        printf("%d\n",t);

    }
    return 0;
}
