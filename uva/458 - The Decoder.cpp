#include <stdio.h>

int main()
{
    char kalimat[256];
    char decode[256];
    char *pointer;
    char *decode_ptr;

    while(gets(kalimat))
    {
        pointer = &(kalimat[0]);
        decode_ptr = &(decode[0]);
        while(*pointer!='\0')
        {
            *decode_ptr = *pointer - 7;
            decode_ptr++;
            pointer++;
        }
        *decode_ptr = '\0';
        puts(decode);
    }
    return 0;
}
