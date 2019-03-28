#include <cstdio>

 int main()
 {
     int t,n,g,gg;
     char s[99];
     scanf("%d%d",&t,&g);
     while(t--)
     {
         scanf("%s%d",s,&gg);
         printf("Welcome %s",s);
         if(gg!=g)
            printf(", ;)");
        printf("\n");
     }
     return 0;
 }
