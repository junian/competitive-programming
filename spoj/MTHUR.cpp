#include <cstdio>
#include <algorithm>
#define INF 999999999
using namespace std;
#define MAX 100032
int a[MAX],b[MAX],c[MAX];
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
    int t,n,m,medi,res;
    //scanf("%d", &t);
    t=getNum<int>();
    while(t--)
    {
        //scanf("%d", &n);
        n=getNum<int>();
        for(int i=0;i<n;i++)
            //scanf("%d", &a[i]);
            a[i] = getNum<int>();
        for(int i=0;i<n;i++)
        {
            //scanf("%d", &b[i]);
            b[i]=getNum<int>();
            b[i] = a[i]-b[i];
        }
        sort(b,b+n);
        if(n%2==1)
            medi = b[(n+1)>>1];
        else
            medi = b[n>>1];
        int mini = INF;
//        scanf("%d", &m);
        m=getNum<int>();
        for(int i=0;i<m;i++)
            //scanf("%d", &c[i]);
            c[i] = getNum<int>();
        sort(c,c+m);
        for(int i=0;i<m;i++)
        {
            int x = abs(c[i]-medi);
            if(x<mini)
            {
                res=i;
                mini=x;
            }
            else if(x == mini && c[i]<c[res])
                res=i;
        }
        int sum = INF;
        for(int i=min(res+1,m-1);i>=max(res-1,0);i--)
        {
            int x=0;
            for(int j=0;j<n;j++)
                x+=abs(b[j]-c[i]);
            if(x<=sum)
            {
                sum = x;
                res = i;
            }
        }
        printf("%d\n", c[res]);
    }
    return 0;
}

