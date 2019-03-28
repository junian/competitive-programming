#include <cstdio>
#include <map>

using namespace std;

map<long long,int> m;
map<long long,int> l;

int s(long long x)
{
    if(x==0)
        return 0;
    long long r=m[x];
    if(r==0)
    {
        long long a=x;
        r=s(x/10)+x%10;
        m[x]=r;
    }
    return r;
}

int main()
{
    m.clear();
    l.clear();
    int t,i=-1;
    long long n;
    for(n=1;n<=1000000000;n++)
    {
        while(1)
        {
            i++;

            if(s(i*i)==s(i)*s(i))
            {
                printf("%d ",i);
                l[n]=i;

                break;
            }
        }
    }
    scanf("%d",&t);
    while(t-->0)
    {
        scanf("%d",&n);
        printf("%d\n",l[n]);
    }
    return 0;
}
