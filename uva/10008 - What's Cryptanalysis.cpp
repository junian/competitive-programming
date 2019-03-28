#include <cstdio>
#include <algorithm>
#include <cctype>
#include <map>

using namespace std;

typedef struct huruf
{
    char c;
    unsigned long long i;
};

bool cmp(huruf a, huruf b)
{
    return a.i>b.i;
}

int main()
{
    char x;
    map<char,unsigned long long> m;
    int n=0,i;
    huruf g[26];
    while((x=getchar())!='\n')
        n=n*10+(x-'0');
    while(n--)
    {
        while((x=getchar())!='\n')
        {
            x=toupper(x);
            if(x>='A' && x<='Z')
                m[x]+=1;
        }
    }
    n=0;
    for(x='A';x<='Z';x++)
    {
        if(m[x]>0)
        {
            g[n].c=x;
            g[n++].i=m[x];
        }
    }
    sort(g,g+n,cmp);
    for(i=0;i<n;i++)
        printf("%c %llu\n",g[i].c,g[i].i);
    return 0;
}
