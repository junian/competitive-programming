#include <map>
#include <cstdio>
#include <string>

using namespace std;


int main()
{
    int t,a,b;
    char nama[100];
    scanf("%d", &t);
    map<int, map<int, string> > girls;
    while(t--)
    {
        scanf("%d %d %s", &a, &b, nama);
        girls[a][b] = nama;
    }
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d %d", &a, &b);
        printf("%s\n", girls[a][b].c_str());
    }
    return 0;
}
