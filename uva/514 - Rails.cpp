#include <cstdio>
#include <stack>

using namespace std;

int main()
{
    int n,i,j;
    int x[1000];
    while(1)
    {
        scanf("%d",&n);
        if(n==0)
            break;

        while(1)
        {
            scanf("%d",&x[0]);

            if(x[0]==0)
            {
                printf("\n");
                break;
            }

            for(i=1;i<n;i++)
                scanf("%d",&x[i]);
            j=0;i=1;
            stack<int> a;
            while(1)
            {
                if(i>n)
                    break;
                if(i!=x[j])
                {
                    if(!a.empty() && a.top()==x[j])
                    {
                        a.pop();
                        j++;
                    }
                    else
                    {
                        while(1)
                        {
                            if(i>n || i==x[j])
                                break;
                            a.push(i);
                            i++;
                        }
                    }
                }
                else
                {
                    j++;
                    i++;
                }
            }
            if(a.empty())
                printf("Yes\n");
            else
                printf("No\n");
        }
    }
    return 0;
}
