#include <cstdio>
#define MAX 77

int main()
{
    int a[MAX];
    a[1] = 1;
    a[2] = a[3] = 2;
    for(int i=4;i<MAX;i++)
        a[i] = a[i-2]+a[i-3];
    int n;
//    for(n=1;n<=76;n++)
    while(scanf("%d",&n)!=EOF)
    {
        printf("%d\n",a[n]);
    }
    return 0;
}
