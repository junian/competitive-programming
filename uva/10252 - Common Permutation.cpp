#include <iostream>
#include <set>

using namespace std;

string permutation(string a, string b);

int main()
{
    string a;
    string b;
    string hasil;
    
    while(cin>>a>>b)
    {
        hasil = permutation(a, b);
        if(hasil != "")
            cout<<hasil<<endl;
    }
    
    return 0;
}

string permutation(string a, string b)
{
    multiset<char> x;
    multiset<char> y;
    multiset<char> hasil;
    
    int i;
    
    for(i=0; i<a.length(); i++)
    {
        x.insert(a.at(i));
    }
    
    for(i=0; i<b.length(); i++)
    {
        y.insert(b.at(i));
    }
    
    if(x.size()>y.size())
    {
        multiset<char> temp = x;
        x = y;
        y = temp;
    }
    
    multiset<char>::iterator find;
    
    for(multiset<char>::iterator iter = x.begin(); iter != x.end(); iter++)
    {
        find = y.find(*iter);
        if(find!=y.end())
        {
            hasil.insert(*iter);
            y.erase(find);        
        }    
    }
    
    string result = "";
    
    for(multiset<char>::iterator iter = hasil.begin(); iter!=hasil.end(); iter++)
    {
        result = result + *iter;
    }
    
    return result;
}
