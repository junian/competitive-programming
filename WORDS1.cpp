#include<iostream>
#include<cstring>
#include<cstdlib>
#include <cstdio>

using namespace std;

int color[26];

int getcolor ( int a )
{
    return color[a] = (color[a] == a ? a : getcolor ( color[a] ));
}

int main()
{
    int t,startind[26],endind[26],count[26],ca,cb,set,l,k,m,x,y;

    long long int n,i;

    char s[1008];

    scanf("%d",&t);

    while(t--)
    {
        set=1;k=0;m=1;
        scanf("%lld",&n);

        memset(startind,0,sizeof(startind));
        memset(endind,0,sizeof(endind));
        memset(count,0,sizeof(count));

        for(i=0;i<26;i++) color[i]=i;

        for(i=0;i<n;i++)
        {
            scanf("%s",s);
            x=s[0]-97;y=s[strlen(s)-1]-97;
            startind[x]++;endind[y]++;count[x]++;count[y]++;
            ca=getcolor(x);cb=getcolor(y);
            if(ca==cb) continue;
            color[cb]=ca;
        }

        for(i=0;i<26;i++) if(count[i]!=0) {l=getcolor(i);break;}

        for(;i<26&&set;i++) if(count[i]!=0 && getcolor(i)!=l) set=0;

        for(i=0;i<26 && m && k<=2;i++)
        {
            if(abs(startind[i]-endind[i])==1) k++;
            if(abs(startind[i]-endind[i])>1) m=0;
        }

        if(k<=2&&set==1&&m) printf("Ordering is possible.\n");

        else printf("The door cannot be opened.\n");
    }

    return 0;
}
