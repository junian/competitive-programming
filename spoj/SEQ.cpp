#include <cstdio>
#include <vector>
#define MOD 1000000000
using namespace std;

typedef vector< vector <long long> > vvl;
typedef vector< long long > vl;

vvl mul(const vvl &a, const vvl &b)
{
    vvl c(a.size());
    for(int i=0;i<c.size();i++)
        c[i].resize(b[0].size());
        
    for(int i=0;i<a.size();i++)
    {
        
        for(int j=0;j<b[i].size();j++)
        {
            for(int k=0;k<a[i].size();k++)
            {
                c[i][j] = (c[i][j] + a[i][k]*b[k][j]) % MOD;
            }
        }
        
    }
    return c;
}

vvl power(const vvl &a, int n)
{
    if(n == 1)
        return a;
    vvl res = power(a,n/2);
    if((n%2) == 1)
        return mul(a,mul(res,res));
    return mul(res,res);
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,p;
        scanf("%d",&n);
        
        vvl awal(1);
        awal[0].resize(n);
        for(int i=0;i<n;i++)
            scanf("%I64d",&awal[0][i]);
        
        vl cc(n);
        for(int i=0;i<n;i++)
            scanf("%I64d",&cc[i]);
            
        vvl matriks(n);
        for(int i=0;i<n;i++)
            matriks[i].resize(n);
            
        for(int i=0;i<n;i++)
            for(int j=0;j<n-1;j++)
                matriks[i][j] = 0;
        for(int i=0;i<n-1;i++)
            matriks[i+1][i]=1;
        for(int i=0;i<n;i++)
            matriks[i][n-1] = cc[n-i-1];
        //for(int i=0;i<n;i++)
        //{
          //  for(int j=0;j<n;j++)
            //    printf("%I64d ", matriks[i][j]);
            //puts("");
        //}
        scanf("%d",&p);
        vvl hasilmat;
        if(p>1)
            hasilmat = mul(awal,power(matriks,p-1));
        else
            hasilmat = awal;
//        vvl hasilakhir = mul(awal,hasilmat);
        printf("%I64d\n",hasilmat[0][0]);
    }
    return 0;
}
