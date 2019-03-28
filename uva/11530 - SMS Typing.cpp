#include <cstdio>
#include <map>
using namespace std;
int main()
{
    map<char, int> m;
    int i,j,a;
    char x;
    m[' ']=1;
    for(i=1;i<=3;i++)
        for(j=0;j<5;j++)
            m['a'+j*3+i-1]=i;
    m['p']=m['t']=m['w']=1;
    m['q']=m['u']=m['x']=2;
    m['r']=m['v']=m['y']=3;
    m['s']=       m['z']=4;
    i=0;
    while((x=getchar())!='\n')
        i= i*10+(x-'0');
    for(a=1;a<=i;a++)
    {
        j=0;
        while((x=getchar())!='\n')
            j+=m[x];
        printf("Case #%d: %d\n",a,j);
    }
    return 0;
}
