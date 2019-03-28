#include <cstdio>
#include <cstdlib>

int cmp(const void*a, const void*b)
{
    return (*(int*)a-*(int*)b);
}

int main()
{
    int c[143];
    int i,n,a,b,*d;
    for(i=0;i<143;i++)
        c[i] = i*i;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d%d",&a,&b);
        i = a*a+b*b;
        d = (int*)bsearch(&i, c, 143, sizeof(int), cmp);
        if(d==NULL)
            puts("NO");
        else
            printf("YES %d\n",d-c);
    }
    return 0;
}
