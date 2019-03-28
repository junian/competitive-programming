#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
#include <string>
using namespace std;
int main()
{
    char a[32],b[32],c[32],d[32],s[2];
    char bb[16][5] = {"0000","0001","0010","0011",
                      "0100","0101","0110","0111",
                      "1000","1001","1010","1011",
                      "1100","1101","1110","1111"};
    int i,n;
    map<char,string> m;
    for(i=0;i<=9;i++)
        m[i+'0']=bb[i];
    for(i=10;i<16;i++)
        m['A'+i-10]=bb[i];
    for(i=10;i<16;i++)
        m['a'+i-10]=bb[i];
    unsigned long x,y;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%s%s%s",a,s,b);
        x=strtoul(a,NULL,16);
        y=strtoul(b,NULL,16);
        sprintf(a,"%X",x);
        sprintf(b,"%X",y);

        if(s[0]=='+')
            x=x+y;
        else
            x=x-y;
        strcpy(c,"0");
        strcpy(d,"0");
        y=strlen(a);
        for(i=0;i<3-y;i++)
            strcat(c,"0000");
        for(i=0;i<y;i++)
            strcat(c,m[a[i]].c_str());
        y=strlen(b);
        for(i=0;i<3-y;i++)
            strcat(d,"0000");
        for(i=0;i<y;i++)
            strcat(d,m[b[i]].c_str());
        printf("%s %s %s = %lu\n",c,s,d,x);
    }
}
