#include <cstdio>
int main()
{
    int t;
    int n;
    scanf("%d",&t);
    for(int c=1;c<=t;c++)
    {
        scanf("%d",&n);
        int aw = n;
        do
        {
            int c = 0;
            while(n>0)
            {
                int d = n%10;
                c += d*d;
                n/=10;
            }
            n = c;
        }while(n/10!=0);
        printf("Case #%d: %d is ",c,aw);
        if(n==1 || n==7)
            puts("a Happy number.");
        else
            puts("an Unhappy number.");
    }

    //for(int i=1;i<=9;i++)
//    {
//        int n = i;
//        int step=0;
//        do{
//            step++;
//            int c=0;
//            while(n>0)
//            {
//                c += (n%10)*(n%10);
//                n/=10;
//            }
//            n = c;
//           // printf(">> %d\n",n);
//        }while(n!=1 && n/10!=0);
//        printf("%d\n",n);
//    }
    return 0;
}
