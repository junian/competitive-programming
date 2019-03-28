#include <cstdio>
#include <vector>

#define MAX 2147483648

using namespace std;

typedef vector<vector<unsigned int> > vvi;

unsigned int mod;

vvi mul(vvi a, vvi b)
{
    vvi c(a.size());
    for(int i=0;i<a.size();i++)
        c[i].resize(b[0].size());
    for(int i=0;i<a.size();i++)
    {
        for(int j=0;j<b[0].size();j++)
        {
            for(int k=0;k<b.size();k++)
            {
                c[i][j] = (c[i][j] + a[i][k]*b[k][j]) % mod;
            }
        }
    }
    return c;
}

vvi power(vvi a, int p)
{
    if(p == 1)
        return a;
    if(p%2 == 0)
        return power(mul(a,a),p/2);
    return mul(a,power(mul(a,a),p/2));
}

int pow2(int n, int p)
{
    if(p==0)
        return 1;
    if(p==1)
        return n;
    if(p%2 == 0)
        return pow2(n*n,p/2);
    return n*pow2(n*n,p/2);
}

int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        vvi awal(1);
        awal[0].resize(2);
        awal[0][0] = 0;
        awal[0][1] = 1;
        
        vvi matriks(2);
        matriks[0].resize(2);
        matriks[1].resize(2);
        matriks[0][0] = 0;
        matriks[0][1] = 1;
        matriks[1][0] = 1;
        matriks[1][1] = 1;
        
        mod = pow2(2,m);
        if(n>0)
            matriks = power(matriks,n);
        vvi res = mul(awal,matriks);
        if(n==0)
            printf("%u\n",awal[0][0]);
        else
            printf("%u\n",res[0][0]);
    }
    return 0;
}
