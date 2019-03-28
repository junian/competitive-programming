#include <cstdio>
#include <cstring>

int main()
{
    char kalimat[256];
    char *kal = "AEHIJLMOSTUVWXYZ12358";
    char *rev = "A3HILJMO2TUVWXY51SEZ8";
    int i, j, length, lengthkal, a;
    int pal;

    while(gets(kalimat))
    {
        length = strlen(kalimat)-1;
        i=0;
        j=length;
        pal = 0;

        while(i<=j)
        {
            if(kalimat[i] != kalimat[j])
            {
                break;
            }
            i++;
            j--;
        }

        if(i>j)
        {
            pal += 1;
        }

        i=0;
        j=length;
        lengthkal = strlen(kal);
        while(i<=j)
        {
            for(a=0; a<lengthkal; a++)
            {
                if(kalimat[i] == kal[a])
                    break;
            }

            if(a == lengthkal)
            {
                break;
            }
            else if(rev[a] != kalimat[j])
            {
                break;
            }

            i++;
            j--;
        }

        if(i>j)
        {
            pal += 2;
        }

        printf("%s -- ", kalimat);

        switch(pal)
        {
            case 0:
                puts("is not a palindrome.");
                break;
            case 1:
                puts("is a regular palindrome.");
                break;
            case 2:
                puts("is a mirrored string.");
                break;
            case 3:
                puts("is a mirrored palindrome.");
                break;
            default:
                break;
        }
        printf("\n");

    }
    return 0;
}
