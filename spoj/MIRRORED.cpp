#include <stdio.h>

int main()
{
    char x[3];
    printf("Ready\n");
    while(1)
    {
        gets(x);
        if(x[0] == ' ' && x[1] == ' ')
            break;
        if((x[0] == 'p' && x[1] == 'q') ||
           (x[0] == 'q' && x[1] == 'p') ||
           (x[0] == 'b' && x[1] == 'd') ||
           (x[0] == 'd' && x[1] == 'b'))
           {
               printf("Mirrored pair\n");
           }
        else
            printf("Ordinary pair\n");
    }
    return 0;
}
