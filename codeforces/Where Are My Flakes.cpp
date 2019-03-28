#include <cstdio>
#include <cstring>

int main()
{
    char s[10][100];
    int n,m,a;
    int bataskiri;
    int bataskanan;
    scanf("%d%d",&n,&m);
    bataskiri=0;
    bataskanan=n+1;
    while(m--)
    {
        scanf("%s %s %s %s %d",s[0],s[1],s[2],s[3],&a);
        if(s[2][0] == 'l' && a<bataskanan)
            bataskanan = a;
        else if(s[2][0] == 'r' && a>bataskiri)
            bataskiri = a;
    }
//    printf("%d %d\n",bataskanan,bataskiri);
    if(bataskanan-bataskiri-1>0)
        printf("%d\n",bataskanan-bataskiri-1);
    else
        puts("-1");
    return 0;
}
