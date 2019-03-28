#include<iostream>
#define x for(j=0;j<=i;j++)
using namespace std;main(){int t=101,n,i,j,a[t][t];cin>>t;while(t--){cin>>n;for(i=0;i<n;i++)x cin>>a[i][j];for(i=n-2;i>=0;i--)x a[i][j]+=max(a[i+1][j],a[i+1][j+1]);cout<<**a<<endl;}}
