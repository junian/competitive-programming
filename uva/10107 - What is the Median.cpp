#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
    unsigned int t[10001];
    unsigned int i=0;
    unsigned int n;
    while(scanf("%u",&n)!=EOF)
    {
        t[i++]=n;
        sort(t,t+i);
        if(i%2==0)
        {
            n = (i/2);
            n = (t[n-1]+t[n])/2;
        }
        else
            n = t[(i/2)];
        printf("%u\n",n);
    }
    return 0;
}
