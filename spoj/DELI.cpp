#include <cstdio>
#include <cstring>
#include <map>
#include <string>

using namespace std;

int main()
{
    int a,b,i;
    char c[256],d[256];
    map<string, string> s;
    scanf("%d%d",&a,&b);
    for(i=0;i<a;i++)
    {
        scanf("%s%s",c,d);
        s[c]=d;
    }
    while(b--)
    {
        scanf("%s",c);
        i=strlen(c)-1;
        if(s[c].compare("")!=0)
            printf("%s\n",s[c].c_str());
        else
        {
            if(i>=1 && c[i]=='y' && (c[i-1]!='a' && c[i-1]!='i' && c[i-1]!='u' && c[i-1]!='e' && c[i-1]!='o'))
            {
                c[i]='\0';
                strcat(c,"ies");
            }
            else if(i>=0 && (c[i]=='o' || c[i]=='s' || c[i]=='x'))
                strcat(c, "es");
            else if(i>=1 && c[i]=='h' && (c[i-1]=='s' || c[i-1]=='c'))
                strcat(c, "es");
            else
                strcat(c, "s");
            printf("%s\n",c);
        }
    }
    return 0;
}
