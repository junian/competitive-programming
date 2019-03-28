#include <cstdio>
#include <map>
using namespace std;
int main()
{
    int n=0,m;
    map<char,bool> s;
    char y;
    while((y=getchar())!='\n')
        n=10*n+(y-'0');
    while(n--)
    {
        s.clear();
        m=0;
        while((y=getchar())!='\n')
            if(!s[y])
            {
                s[y]=true;
                m++;
            }
        printf("%d\n",m);
    }
}
