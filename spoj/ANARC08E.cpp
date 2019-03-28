#include <stdio.h>

int main()
{
//    unsigned int fakt[21];
//    unsigned int i, j;
//    unsigned int f;
//    fakt[0] = fakt[1] = 1;
//    for(i=2; i<=20; i++)
//        fakt[i] = fakt[i-1] * i;
//    for(i=0; i<=10; i++)
//    {
//        for(j=0; j<=10; j++)
//        {
//            f=fakt[i+j]/(fakt[i]*fakt[j]);
//            if(f==i+j)
//                printf("%u+%u=%u\n", i, j, f);
//            else
//                printf("%u+%u!=%u\n", i, j, f);
//        }
//    }
    int a, b;
    while(1)
    {
        scanf("%d %d", &a, &b);
        if(a==-1 && b==-1)
            break;
        if(a==1 || b==1)
            printf("%d+%d=%d\n", a, b, a+b);
        else
            printf("%d+%d!=%d\n", a, b, a+b);
    }
    return 0;
}
