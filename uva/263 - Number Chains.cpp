#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
int main()
{
    char x[100];
    unsigned long long a,b,c,d,e,f,i,m[1000];
    while(scanf("%llu",&a)!=EOF)
    {
        printf("Original number was %llu\n",f);
        e=0;
        while(1)
        {
            itoa(a,x,10);
            d=strlen(x);
            a=0;
            b=0;
            for(i=0;i<d;i++)
            {
                a=a*10+(x[i]-'0');
                b=b*10+(x[d-i-1]-'0');
            }
            c = b-a;
            printf("\n")
            m[e++]=c;

        }
    }
    return 0;
}
