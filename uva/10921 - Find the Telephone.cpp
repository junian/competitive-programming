#include <cstdio>
#include <map>
using namespace std;
int main()
{
    map<char,char> m;
    char x,y='2';
    char z[32];
    int i;
    for(x='A';x<='P';x+=3)
        m[x]=m[x+1]=m[x+2]=y++;
    m['S']='7';
    m['T']=m['U']=m['V']='8';
    m['W']=m['X']=m['Y']=m['Z']='9';
    m['-']='-';
    m['0']='0';
    m['1']='1';
    while(scanf("%s",z)!=EOF)
    {
        for(i=0;z[i]!='\0';i++)
            putchar(m[z[i]]);
        printf("\n");
    }
    return 0;
}
