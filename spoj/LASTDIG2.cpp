#include <cstdio>
#include <cstring>
int main()
{
    char s[1024];
    int i, j, t, a;
    unsigned long long b;
    scanf("%d", &t);
    while(t>0)
    {
        t--;
        scanf("%s %llu", s, &b);
        if(b==0)
            printf("1\n");
        else
        {
            a = (s[strlen(s)-1]-'0');
            b = b % 4;
            b = b==0?4:b;
            j=1;
            for(i=0; i<b; i++)
                j *= a;
            j = j % 10;
            printf("%d\n", j);
        }
    }
    return 0;
}

