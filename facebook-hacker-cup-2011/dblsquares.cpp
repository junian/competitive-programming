#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

#define MAX 46341

int main()
{
   unsigned long long quad[MAX+1];
   unsigned long long i;
   for(i=0; i<=MAX; i++)
      quad[i] = i*i;
   unsigned long long t,x,a,n,y;
   scanf("%I64u", &t);
   while(t--)
   {
      scanf("%I64u", &x);
      n=0;
      y = x>>1;
      for(i=0; quad[i]<=y; i++)
         if(binary_search(quad, quad+MAX+1, x-quad[i]))
            n++;
      printf("%I64u\n", n);
         
   }   
   return 0;
}   
