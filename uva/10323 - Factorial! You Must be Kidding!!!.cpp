#include <cstdio>
#define MAX 13
#define MIN 8

int main()
{
    int data;

    while(scanf("%d", &data)!=EOF)
    {
        if(data<0)
        {
            data=-data;
            if(data%2==1)
                puts("Overflow!");
            else
                puts("Underflow!");
        }
        else
        {
            if(data<MIN)
                puts("Underflow!");
            else if(data>MAX)
                puts("Overflow!");
            else
            {
                switch(data)
                {
                    case 8:
                        puts("40320");
                        break;
                    case 9:
                        puts("362880");
                        break;
                    case 10:
                        puts("3628800");
                        break;
                    case 11:
                        puts("39916800");
                        break;
                    case 12:
                        puts("479001600");
                        break;
                    case 13:
                        puts("6227020800");
                        break;
                }
            }
        }

    }
    return 0;
}
