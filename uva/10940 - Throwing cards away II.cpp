#include <stdio.h>

int main()
{
    int two[20] = {1, 2, 4, 8, 16, 32, 64 ,128,
                256, 512, 1024, 2048, 4096, 8192,
                16384, 32768, 65536, 131072, 262144,
                524288};
    int n, i, z;
    while(1)
    {
        scanf("%d",&n);
        if(n<=0)
            break;
        for(i=19; i>=0; i--)
        {
            z = n - two[i];
            if(z >= 0)
                break;
        }
        printf("%d\n", z==0?n:2*z);
    }
    return 0;
}
