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
        sw=(sw+1)%2;
    return c;
}

int main()
{
    int x[100001];
    int n,i,j;
    bool swp;
    while(1)
    {
        scanf("%d",&n);
        if(n==0)
            break;
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
        if(sw==1)
            printf("Marcelo\n");
        else
            printf("Carlos\n");
    }
    return 0;
}
