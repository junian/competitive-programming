#include <stdio.h>

//int josephus(int n, int k)
//{
//    if(n == 1)
//        return 0;
//    return (josephus(n-1, k) + k) % n;
//}

int main()
{
    int two[27] = {1, 2, 4, 8, 16, 32, 64 ,128,
                256, 512, 1024, 2048, 4096, 8192,
                16384, 32768, 65536, 131072, 262144,
                524288, 1048576, 2097152, 4194304,
                8388608, 16777216, 33554432, 67108864};

//    int k=2;
//    int *jos = (int*) malloc(sizeof(int) * 99000000);
//    jos[0] = 0;
//    for(i=1; i<99000000; i++)
//    {
//        jos[i] = (jos[i-1] + k) % (i+1);
//    }
    char input[5];
    int n, t, i, z;
    while(1)
    {
        gets(input);
        if(input[0] == '0' && input[1] == '0' && input[3] == '0')
            break;
        n = 10*(input[0]-'0');
        n += (input[1]-'0');
        t=1;
        z = input[3]-'0';
        for(i=0; i<z; i++)
            t *= 10;
        n *= t;
        for(i=26; i>=0; i--)
        {
            z = n - two[i];
            if(z >= 0)
                break;
        }
        printf("%d\n", 2*z+1);
    }
    return 0;
}
