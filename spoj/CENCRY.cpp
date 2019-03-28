#include <cstdio>
#include <map>
using namespace std;
int main()
{
    int i=0,n=0;
    char x;
    map<char, int> j,p;
    char v[7]="aeiou";
    char k[23]="bcdfghjklmnpqrstvwxyz";
    for(i=0;i<5;i++)
        p[v[i]]=i;
    for(i=0;i<21;i++)
        p[k[i]]=i;
    while((x=getchar())!='\n')
        n=n*10+(x-'0');
    while(n--)
    {
        j.clear();
        while((x=getchar())!='\n')
        {
            if(x=='a' || x=='i' || x=='u' || x=='e' || x=='o')
                putchar(k[(p[x]+j[x]*5)%21]);
            else
                putchar(v[(p[x]+j[x]*21)%5]);
            j[x]++;
        }
        putchar('\n');
    }
    return 0;
}
