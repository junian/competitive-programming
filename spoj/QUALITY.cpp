#include <cstdio>

int main()
{
    int a[3],b[3];
    int n=1,s,t,i;
    while(scanf("%d %d %d %d %d %d",&a[0],&a[1],&a[2],&b[0],&b[1],&b[2])!=EOF)
    {
        s=0;
        t=0;
        for(i=0;i<3;i++)
        {
            if(a[i]!=0)
            {
                s++;
                t += a[i]+(b[i]-1)*1200;
            }
        }
        printf("team %d: %d, %d\n",n,s,t);
        n++;
    }
    return 0;
}
