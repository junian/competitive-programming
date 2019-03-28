#include <cstdio>
int main()
{
    int t,i;
    int n[1001];
    scanf("%d",&t);
    for(i=0;i<t;i++)
        scanf("%d",&n[i]);
    for(i=t-1;i>=0;i--)
        printf("%d\n",n[i]);
    return 0;
}
