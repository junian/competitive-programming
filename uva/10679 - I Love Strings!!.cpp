#include <cstdio>
#include <cstdlib>

int main()
{
    int k, q, r;
    char s[100001], t[1001];
    char *p;

    scanf("%d", &k);
    while(k>0)
    {
        k--;
        scanf("%s", s);
        scanf("%d", &q);
        while(q>0)
        {
            q--;
            scanf("%s", t);
            p = &(s[0]);
            while(*p!='\0')
            {
                if(*p == t[0])
                {
                    for(r=1; t[r]!='\0'; r++)
                    {
                        if((*(p+r) == '\0') || (*(p+r) != t[r]))
                            break;
                    }
                    if(t[r] == '\0')
                    {
                        printf("y\n");
                        break;
                    }
                }
                p++;
            }
            if(*p == '\0')
                printf("n\n");
        }
    }

    return 0;
}
