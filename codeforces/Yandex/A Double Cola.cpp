#include <cstdio>
#define MAX 1000000000

int main()
{
    char name[5][32] = {"Sheldon", "Leonard", "Penny", "Rajesh", "Howard"};
    int scale[29] = {0, 1, 6, 16, 36, 76, 156, 316, 636, 1276, 2556, 5116, 10236, 20476, 40956, 81916, 163836, 327676, 655356, 1310716, 2621436, 5242876, 10485756, 20971516, 41943036,
83886076, 167772156, 335544316, 671088636};
    int n;
    
    scanf("%d",&n);
    //int z=1;
    //int s=1;
    //for(int i=1;i<=MAX;i=i+5*z,z*=2)
    //    printf("%d. %d, ",s++,i);
    //while(n > 5)
        //n = (n%5);
    int i=1;
    int z=1;
    for(i=1;i<=28;i++,z=z*2)
        if(n < scale[i])
        {
            i--;
            break;
        }
    n = n-scale[i];
    n = n / z;
    printf("%d\n",n);
    puts(name[n]);
    scanf("%d",&n);
    return 0;
}
