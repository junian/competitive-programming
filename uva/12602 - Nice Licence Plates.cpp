#include <cstdio>

int main()
{
    char chara[100];
    int n;
    scanf("%d", &n);
    while(n--)
    {
        scanf("%s", chara);
        int first = (chara[0]-'A')*26*26 + (chara[1]-'A')*26 + (chara[2] - 'A');
        int second = (chara[4]-'0')*1000 + (chara[5]-'0')*100 + (chara[6]-'0')*10 + (chara[7]-'0');
        int delta = first -second;
        delta = delta<0?-delta:delta;
        if(delta <= 100)
        {
            puts("nice");
        }
        else
            puts("not nice");
    }
    return 0;
}