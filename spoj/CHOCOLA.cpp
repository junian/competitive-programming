#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
    int t,a,b,c,d,e,i;
    int x[1001];
    int y[1001];

    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&a,&b);

        e=0;
        a-=2;
        b-=2;

        for(i=0;i<=a;i++)
            scanf("%d",&x[i]);

        for(i=0;i<=b;i++)
            scanf("%d",&y[i]);

        sort(x,x+a+1);
        sort(y,y+b+1);

        c=d=1;

        while(a>=0 || b>=0)
        {
            if(a<0 || (b>=0 && y[b]>x[a]))
            {
                e += d*y[b];
                b--;
                c++;
            }
            else
            {
                e += c*x[a];
                a--;
                d++;
            }
        }

        printf("%d\n",e);
    }

    return 0;
}
