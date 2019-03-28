#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;
int main()
{
    char base[20] = "0123456789ABCDEF";
    int i,a,b;
    char c[256],d[256],e,f[256];
    unsigned long long l;
    map<char, int> m;
    for(i=1;base[i]!='\0';i++)
        m[base[i]]=i+1;
    for(i=11;i<=16;i++)
        m['a'+i-11]=i;
    m['0']=2;
    while(scanf("%d%d%s",&a,&b,c)!=EOF)
    {
        e=*max_element(c,c+strlen(c));
        if(m[e]<=a)
        {
            l=strtoull(c,NULL,a);
            if(l==0)
                printf("%s base %d = 0 base %d\n",c,a,b);
            else
            {
                i=0;
                while(l>=b)
                {
                    d[i++]=base[l%b];
                    l=l/b;
                }
                d[i++]=base[l];
                d[i]='\0';
                for(int j=0;d[j]!='\0';j++)
                    f[i-j-1]=d[j];
                f[i]='\0';
                printf("%s base %d = %s base %d\n",c,a,f,b);
            }
        }
        else
            printf("%s is an illegal base %d number\n",c,a);
    }
    return 0;
}
