#include <cstdio>
#include <cstdlib>

using namespace std;

int main()
{
    char **fact;
    int num[2600];
    int last = 0;
    int n;
    char *p;

    fact = (char**) malloc(sizeof(char*)*1001);
    for(int i=0; i<=1000; i++)
        fact[i] = (char*) malloc(sizeof(char)*2600);
    num[0] = 1;

    fact[0][0] = fact[1][0] = '1';
    fact[0][1] = fact[1][1] = '\0';

    for(int i=1; i<=1000; i++)
    {
        for(int j=0; j<=last; j++)
        {
            num[j] *= i;
        }
        for(int j=0; j<last; j++)
        {
            num[j+1] += num[j]/10;
            num[j] = num[j]%10;
        }
        while(num[last]>=10)
        {
            num[last+1] = num[last]/10;
            num[last] = num[last]%10;
            last++;
        }

        p = fact[i];

        for(int j=last; j>=0; j--)
        {
            *p = num[j] + '0';
            p++;
        }
        *p = '\0';
    }

    while(scanf("%d", &n)!=EOF)
    {
        printf("%d!\n%s\n", n, fact[n]);
    }


    for(int i=0; i<=1000; i++)
        free(fact[i]);
    free(fact);

    return 0;
}
