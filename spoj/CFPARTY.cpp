#include <cstdio>
int main()
{
    int i,j,n;
    for(i=1;i<100;i++)
    {
        n=i;
        j=0;
        while(j<=n)
        {
            j++;
            n--;
        }
        printf("%d\n",n);
    }
    return 0;
}
