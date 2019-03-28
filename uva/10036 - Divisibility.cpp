#include <cstdio>
#include <cmath>

int main()
{
    int m = 0, n = 0, k = 0;
    long long limit = 0, total = 0;
    int i = 0, j = 0;
    int sign = 0;
    int angka[10001];
    bool divi = false;

    scanf("%d", &m);
    while(m>0)
    {
        m--;
        scanf("%d %d", &n, &k);
        limit = pow(2, n-1);
        for(i=0; i<n; i++)
            scanf("%d", &(angka[i]));

        if(n==1)
        {
            if(angka[0]%k == 0)
                divi = true;
            else
                divi = false;
        }
        else{
            divi = false;
            for(i=0; i<limit; i++)
            {
                sign = i;
                if(sign%2==0)
                    total = angka[0] + angka[1];
                else
                    total = angka[0] - angka[1];
                for(j=2; j<n; j++)
                {
                    sign = sign >> 1;
                    if(sign%2==0)
                        total+=angka[j];
                    else
                        total-=angka[j];
                }
                if(total % k == 0)
                {
                    divi = true;
                    break;
                }
            }
        }

        if(divi)
            puts("Divisible");
        else
            puts("Not divisible");
    }

    return 0;
}
