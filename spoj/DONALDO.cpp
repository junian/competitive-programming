#include <cstdio>
//#include <queue>
#include <algorithm>
#define MAX 20032
using namespace std;
int inbox[MAX];
int qu[MAX];
template<typename T>
T getNum()
{
    char c;
    T res;
    while(1)
    {
        c=getchar_unlocked();
        if(c=='\n'||c==' ')continue;
        else
        if(c>='0'&&c<='9')break;
    }
    res=(int)(c-'0');
    while(1)
        {
            c=getchar_unlocked();
            if(c>='0'&&c<='9')res = 10*res + c-'0';
            else break;
        }
        return res;
}

int main()
{
    int t,n,h,m,s,lim;
//    scanf("%d", &t);
    t = getNum<int>();
    for(int tc=1;tc<=t;tc++)
    {
        //scanf("%d", &n);
        n = getNum<int>();
        for(int i=0;i<n;i++)
        {
            //scanf("%d:%d:%d", &h, &m, &s);
            h=getNum<int>();
            m=getNum<int>();
            s=getNum<int>();
            inbox[i] = h*3600+m*60+s;
        }
//        scanf("%d", &lim);
        lim=getNum<int>();
        int total = 1;
        if(n==0)
        {
            total = 0;
        }
        else
        {
            sort(inbox, inbox+n);
//            queue<int> q;
//            q.push(inbox[0]);
            int front=0, end=0;
            qu[end++] = inbox[0];
            int ind = 1;
            while(ind<n)
            {
                if(inbox[ind]-qu[front] < lim)
                    total++;
                else
                    front++;
                qu[end++] = inbox[ind++];
            }
        }
        printf("Case %d: %d\n", tc, total);
    }
    return 0;
}
