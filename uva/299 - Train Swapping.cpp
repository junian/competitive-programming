#include <cstdio>

int sw;

void swap(int *a, int *b)
{
    int c=*a;
    *a=*b;
    *b=c;
}

bool cmp(int a, int b)
{
    bool c=a>b;
    if(c)
        sw++;
    return c;
}

int main()
{
    int x[128];
    int t,n,i,j;
    bool swp;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%d",&x[i]);
        sw=0;j=0;
        do
        {
            j++;
            swp=false;
            for(i=0;i<n-j;i++)
                if(cmp(x[i],x[i+1]))
                {
                    swap(&x[i],&x[i+1]);
                    swp=true;
                }
        }while(swp);
        printf("Optimal train swapping takes %d swaps.\n",sw);
    }
    return 0;
}
