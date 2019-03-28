#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
    int n,m,s,a,b,x,y;
    bool first=true;
    int arr[10024];
    
    while(scanf("%d", &n)!=EOF)
    {
        for(int i=0;i<n;i++)
            scanf("%d", &arr[i]);
        scanf("%d", &m);
        sort(arr, arr+n);
        x=y=-1;
        for(int i=0;i<n-1;i++)
        {
            s = m-arr[i];
            if(binary_search(arr+i+1,arr+n,s))
            {
                if(x==-1 || y-x>s-arr[i])
                {
                    x = arr[i];
                    y = s;
                }
            }   
        }
        /*
        if(!first)
        {
            printf("\n");
        }
        else
            first=false;*/
        printf("Peter should buy books whose prices are %d and %d.\n\n",x,y);
    }
    return 0;
}
