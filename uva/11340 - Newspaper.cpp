#include <cstdio>
#include <map>
using namespace std;

int main()
{
    int t,w,d,i;
    char c[2];
    char x[10001];
    long long p,aa,bb;
    map<char,int> m;
    scanf("%d",&t);
    while(t-->0)
    {
        m.clear();
        scanf("%d",&w);
        while(w-->0)
        {
            scanf("%s %d",c,&d);
            m[c[0]]=d;
        }
        scanf("%d",&w);
        fflush(stdin);
        p=0;
        while(w-->0)
        {
            gets(x);
            for(i=0;x[i]!='\0';i++)
            {
                p+=m[x[i]];
            }
        }
        fflush(stdin);
        aa=p/100;
        bb=p%100;
        if(bb>=10)
            printf("%lld.%lld$\n",aa,bb);
        else
            printf("%lld.0%lld$\n",aa,bb);
    }
    return 0;
}
