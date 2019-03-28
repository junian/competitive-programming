#include <cstdio>

#define MAX 1500

int main()
{
    int ugly[MAX];
    int i = 0, ia = 0, ib = 0, ic = 0, j;
    int a, b, c, res;
    int *p;

    ugly[i] = 1;
    while(true)
    {
        if(i==MAX) break;

        a=2*ugly[ia];
        b=3*ugly[ib];
        c=5*ugly[ic];

        res=a;
        p=&ia;

        if(res>b)
        {
            res=b;
            p=&ib;
        }

        if(res>c)
        {
            res=c;
            p=&ic;
        }
        /*
        for(j=0; j<i; j++)
        {
            if(res==ugly[j])
                break;
        }
        */

        if(ugly[i]!=res)
        {
            i++;
            ugly[i]=res;
        }

        *p = *p+1;
    }

    for(i=0; i<MAX; i++)
    printf("%d\n", ugly[i]);
    printf("The 1500'th ugly number is 859963392.\n");
    return 0;

}
