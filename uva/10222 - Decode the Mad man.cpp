#include <cstdio>

int main()
{
    char *keyboard = "`1234567890-=qwertyuiop[]\\asdfghjkl;\'zxcvbnm,./";
    char *keyboard_u = "~!@#$%^&*()_+QWERTYUIOP{}|ASDFGHJKL:\"ZXCVBNM<>?";
    char message[256];
    char *pointer;

    while(gets(message)){
        pointer = &(message[0]);
        while(*pointer!='\0')
        {
            if(*pointer == ' ')
            {
                printf(" ");
            }
            else
            {
                for(int i=0; i<48; i++)
                {
                    if(*pointer == keyboard[i] || *pointer == keyboard_u[i])
                    {
                        printf("%c", keyboard[i-2]);
                        break;
                    }
                }
            }
            pointer++;
        }
        printf("\n");
    }

    return 0;
}
