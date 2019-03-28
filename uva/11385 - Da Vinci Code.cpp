#include <cstdio>
#include <map>
using namespace std;
int main()
{
    map<int,int> m;
    int a=1,b=2,c,i;
    char s[101];
    char o[101];
    m[1]=1;
    m[2]=2;
    for(i=3;i<=100;i++)
    {
        c=a+b;
        m[c]=i;
        a=b;
        b=c;
    }

}
