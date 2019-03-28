#include <cstdio>

bool isPossible(int a, int b)
{
    return (a==b)|(a-b==1)|(b-a==1);
}
int main()
{
    int a,b,c,d;
    scanf("%d%d",&a,&b);
    scanf("%d%d",&c,&d);
    if(isPossible(a,d) || isPossible(b,c))
        puts("YES");
    else
        puts("NO");
    return 0;
}
