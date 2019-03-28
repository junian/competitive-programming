#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
    int m[10];
    for(int i=0;i<10;i++)
        scanf("%d",&m[i]);
    sort(m,m+10);
    printf("%d\n%d\n%d\n",m[9],m[8],m[7]);
    return 0;
}
