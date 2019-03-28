#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;
int main()
{
    char x[256],y[256];
    unsigned long long a,b;
    char base[38] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    map<char,int> m;
    int i,j,mi,mj;
    bool t;
    for(i=1;base[i]!='\0';i++)
        m[base[i]]=i+1;
    m['0']=2;
    while(scanf("%s%s",x,y)!=EOF)
    {
        t=false;
        mi=m[*max_element(x,x+strlen(x))];
        mj=m[*max_element(y,y+strlen(y))];
        for(i=mi;i<=36;i++)
            for(j=mj;j<=36;j++)
            {
                a=strtoull(x,NULL,i);
                b=strtoull(y,NULL,j);
                if(a==b)
                {
                    t=true;
                    mi=i;
                    mj=j;
                    i=j=37;
                }
            }
        if(!t)
            printf("%s is not equal to %s in any base 2..36\n",x,y);
        else
            printf("%s (base %d) = %s (base %d)\n",x,mi,y,mj);
    }
    return 0;
}
