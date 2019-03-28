#include <stdio.h>

#define MAX 1000001

int getNum(){
    int res=0;
    char c;
    int b=0;
    
    while (1){
     c=getchar_unlocked();
        if(c=='-') b=1;
        if(c==' ' || c=='\n') continue;
        else break;
        
        }
        
        if (c!= '-') res= c - '0';
        while (1){
            c=getchar_unlocked();
            if(c>='0' && c <= '9') res = 10* res + c - '0';
            else break;
            
            }
            
            if (b == 1) res *= -1;
            return res;
}

int n;
int num[MAX];
int sorted[MAX];

long long total;

void merge(int l, int mid, int r)
{
    int ind = 0;
    int i=l;
    int j=mid+1;
    while(1)
    {
        if(i>mid || j>r)
            break;
        if(num[i]<num[j])
        {
            total += (long long) num[i] * (r-j+1);
            sorted[ind++] = num[i++];
        }
        else
            sorted[ind++] = num[j++];
    }
    while(j<=r)
        sorted[ind++] = num[j++];
    while(i<=mid)
        sorted[ind++] = num[i++];
    for(i=0;i<ind;i++)
        num[i+l] = sorted[i];
}

void merge_sort(int l, int r)
{
    if(l<r)
    {
        int mid = (l+r)/2;
        merge_sort(l, mid);
        merge_sort(mid+1, r);
        merge(l,mid,r);
    }
}

int main()
{
    int t,i;
//    scanf("%d", &t);
    t=getNum();
    while(t--)
    {
        //scanf("%d", &n);
        n=getNum();
        for(i=0;i<n;i++)
            //scanf("%d", &num[i]);
            num[i]=getNum();
        total = 0;
        merge_sort(0, n-1);
        //for(i=0;i<n;i++)
        //    printf("%d ", num[i]);
        //puts("");
        printf("%lld\n", total);
    }
    return 0;
}
