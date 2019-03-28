#include <cstdio>
#include <map>
#include <cstring>
#include <string>
using namespace std;
int main()
{
    char x[10][5] = {"063","010","093","079","106","103","119","011","127","107"};
    char o[5];
    map<string, long long> m;
    long long a[2],y;
    int i,c,d;
    char s[1024];
    for(i=0;i<10;i++)
        m[x[i]]=i;
    while(1)
    {
        gets(s);
        if(strcmp(s,"BYE")==0)
            break;
        c=0;d=0;
        a[0]=a[1]=0;
        for(i=0;s[i]!='\0';i++)
        {
            if(s[i]>='0'&& s[i]<='9')
            {
                o[c++]=s[i];
                if(c==3)
                {
                    o[c]='\0';
                    a[d]=a[d]*10 + m[o];
                    c=0;
                }
            }
            else if(s[i]=='+')
                d++;
        }
        y=a[0]+a[1];
        printf("%s",s);
        sprintf(s,"%lld",y);
        for(i=0;s[i]!='\0';i++)
            printf("%s",x[s[i]-'0']);
        printf("\n");

    }
    return 0;
}
