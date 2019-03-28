#include <cstdio>
#define MAX 500000

int tree[MAX][3], inc[MAX];

void init_tree(int seg, int low, int high)
{
    tree[seg][0] = high - low + 1;
    if(low < high)
    {
        int mid = (low + high)/2;
        init_tree(2*seg,low,mid);
        init_tree(2*seg+1,mid+1,high);
    }
}

void update_tree(int seg, int low, int high, int a, int b)
{
    if(b<low || a>high)
        return;

    if(a<=low && high<=b)
    {
        inc[seg] = (inc[seg]+1)%3;
        return;
    }
    int mid = (low+high)/2;
    update_tree(2*seg,low,mid,a,b);
    update_tree(2*seg+1,mid+1,high,a,b);
    for(int i=0;i<3;i++)
    {
        tree[seg][i] = tree[2*seg][(i+3-inc[2*seg])%3] +
            tree[2*seg+1][(i+3-inc[2*seg+1])%3];
    }
}

void query(int seg, int low, int high, int a, int b, int ret[3])
{
    if(b<low || a>high)
    {
        ret[0] = ret[1] = ret[2] = 0;
        return;
    }
    if(a<=low && high<=b)
    {
        int incs = 0;
        for(int k=seg;k>=1;k/=2)
            incs = (incs + inc[k])%3;
        for(int i=0;i<3;i++)
        {
            ret[i] = tree[seg][(i+3-incs)%3];
        }
        return;
    }
    int mid = (low+high)/2;
    int ret1[3] = {0,0,0};
    int ret2[3] = {0,0,0};
    query(2*seg,low,mid,a,b,ret1);
    query(2*seg+1,mid+1,high,a,b,ret2);

    for(int i=0;i<3;i++)
        ret[i] = ret1[i] + ret2[i];
}

int main()
{
    int n,q,a,b,c;
    scanf("%d%d",&n,&q);
    init_tree(1,0,n-1);
    while(q--)
    {
        scanf("%d%d%d",&a,&b,&c);
        if(a==0)
            update_tree(1,0,n-1,b,c);
        else
        {
            int ret[3] = {0,0,0};
            query(1,0,n-1,b,c,ret);
            printf("%d\n",ret[0]);
        }
    }
    return 0;
}
