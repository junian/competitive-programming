#include <stdio.h>

int main()
{
    int ang[11];
    int a, i;
    bool lie;
    char s[10];

    for(a=1; a<=10; a++)
        ang[a] = 0;

    while(1)
    {
        fflush(stdin);
        scanf("%d", &a);
        if(a == 0)
        {
            break;
        }
        else
        {
            fflush(stdin);;
            gets(s);
            if(s[4] == 'h')
                ang[a] = 1;
            else if(s[4] == 'l')
                ang[a] = -1;
            else
            {
                lie = false;
                if(ang[a] !=  0)
                {
                    lie = true;
                }
                else
                {
                    for(i=1; i<a; i++)
                    {
                        if(ang[i] > 0)
                        {
                            lie = true;
                            break;
                        }
                    }
                    for(i=10; i>a; i--)
                    {
                        if(ang[i] < 0)
                        {
                            lie = true;
                            break;
                        }
                    }
                }

                if(lie)
                    printf("Stan is dishonest\n");
                else
                    printf("Stan may be honest\n");

                for(a=1; a<=10; a++)
                    ang[a] = 0;
            }
        }
    }

    return 0;
}
