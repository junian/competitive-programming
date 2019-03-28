#include <cstdio>
#include <cstring>

#define MAX 50

int set[MAX+1];
int tot[MAX+1];

void initSet(int n) { for(int i=0;i<n;i++) set[i] = i, tot[i]=0; }

int findSet(int i) { return set[i] = (set[i] == i ? i : findSet(set[i]) ); };

bool isSameSet(int a, int b) { return findSet(a) == findSet(b); }

void unionSet(int a, int b) { if(!isSameSet(a,b)) { set[findSet(a)] = findSet(b); } };

int main()
{
    int t,n,max,m;
    char s[MAX+32][MAX+32];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",s[0]);

        n = strlen(s[0]);
        max = m = 0;
        initSet(n);
        for(int i=1;i<n;i++)
            scanf("%s",s[i]);
        for(int i=0;i<n-1;i++)
            for(int j=i+1;j<n;j++)
                if(s[i][j] == 'Y')
                    unionSet(i,j);
        for(int i=0;i<n;i++)
        {
            tot[findSet(i)]++;
            if(tot[findSet(i)]>max)
                max = tot[findSet(i)];
        }
        for(int i=0;i<n;i++)
            if(tot[findSet(i)] == max)
            {
                m = i;
                break;
            }
        printf("%d %d\n",m,max);
    }
    return 0;
}
