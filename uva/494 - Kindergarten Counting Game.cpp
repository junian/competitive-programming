#include <stdio.h>

int main()
{
    char kalimat[256];
    char *pointer;
    int count = 0;
    bool isCounting;
    while(gets(kalimat))
    {
        pointer = &(kalimat[0]);
        count = 0;
        isCounting = false;
        while(*pointer != '\0')
        {
            if(((*pointer >= 'A' && *pointer <='Z') || (*pointer >= 'a' && *pointer <= 'z')) && !isCounting)
            {
                isCounting = true;
                count++;
            }
            else if(!((*pointer >= 'A' && *pointer <='Z') || (*pointer >= 'a' && *pointer <= 'z')) && isCounting)
            {
                isCounting = false;
            }
            pointer++;
        }
        printf("%d\n", count);
    }
    return 0;
}
