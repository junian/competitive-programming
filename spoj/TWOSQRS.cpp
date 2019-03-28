#include <cstdio>
#include <set>
#include <algorithm>
using namespace std;
int main()
{
    unsigned long long i,j,x[10000];
    int a=0;
    set<unsigned long long> y;
    for(i=0;i<=10;i++)
        for(j=0;j<=10;j++)
        {
//            printf("%llu + %llu = %llu\n",i,j,i*i+j*j);
            //x[a++] = i*i+j*j;
            y.insert(i*i+j*j);
        }
    //sort(y.begin(),y.end());
    //for(i=0;i<a;i++)
        //printf("%llu\n",y[i]);
    set<unsigned long long>::iterator iter;
    for(iter=y.begin();iter!=y.end();iter++)
        printf("%llu\n",*iter);
    return 0;
}
