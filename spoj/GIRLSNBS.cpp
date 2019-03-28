#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
    int a,b,c,d,t;
    while(1)
    {
        scanf("%d %d", &a, &b);
        if(a==-1 && b==-1)
            break;
        else if(a==0)
            printf("%d\n", b);
        else if(b==0)
            printf("%d\n", a);
        else if(a==b)
            printf("1\n");
        else
        {
            c=max(a,b);
            d=min(a,b)+1;
            t=(c/d);
            if(c%d!=0)t+=1;
            printf("%d\n",t);
        }

    }
    return 0;
}
