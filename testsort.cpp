#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

bool cmp(string a, string b)
{
    return a.compare(b)<0;
}

int main()
{
    string ss[1000];
    int n=3;
    for(int i=0;i<n;i++)
        getline(cin, ss[i]);
    sort(ss,ss+n,cmp);
    for(int i=0;i<n;i++)
        cout<<ss[i]<<endl;
    return 0;
}
