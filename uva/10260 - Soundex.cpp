#include <cstdio>

int main()
{
    char soundex[26] = {'\0', '1', '2', '3', '\0', '1', '2', '\0',
                        '\0', '2', '2', '4', '5', '5', '\0', '1',
                        '2', '6', '2', '3', '\0', '1', '\0', '2',
                        '\0', '2'};
    char kar[21];
    char *p;

    while(gets(kar))
    {
        p=kar;
        while(*p!='\0')
        {
            if(p==kar || soundex[*(p-1) - 'A'] != soundex[*p - 'A'])
            {
                if(soundex[*p - 'A'] != '\0')
                    printf("%c", soundex[*p - 'A']);
            }
            p++;
        }
        printf("\n");
    }
    return 0;
}
