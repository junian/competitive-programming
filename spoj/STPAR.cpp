#include <cstdio>
#include <stack>

using namespace std;

int main()
{
    int n,i,j;
    int m[1001];
    while(1)
    {
        scanf("%d",&n);
        if(n==0)
            break;
        for(i=0;i<n;i++)
            scanf("%d",&m[i]);
        i=1;
        j=0;
        stack<int> a;
        while(1)
        {
            if(j==n)
                break;
            if(m[j]!=i)
            {
                if(!a.empty() && a.top()==i)
                {
                    a.pop();
                    i++;
                }
                else
                {
                    while(j<n && m[j]!=i)
                        a.push(m[j++]);
                }
            }
            else
            {
                i++;
                j++;
            }
        }
        while(!a.empty() && a.top()==i)
        {
            a.pop();
            i++;
        }
        if(a.empty())
            printf("yes\n");
        else
            printf("no\n");

    }
    return 0;
}
