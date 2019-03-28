#include <iostream>
#include <sstream>

using namespace std;

bool isPalindrom(string x);
void showResult(int n);
string reverseAndAdd(string data);

int main()
{
    int t;
    int n;
    cin>>t;
    while(t>0)
    {
        t--;
        cin>>n;
        showResult(n);
    }
}

void showResult(int n)
{
    stringstream str;
    str<<n;
    string data = str.str();
    
    int iteration = 0;
    
    while(iteration<1000)
    {
        if(isPalindrom(data))
        {
            cout<<iteration<<" "<<data<<endl;
            return;
        }
        data = reverseAndAdd(data);
        iteration++;
    }
    
}

string reverseAndAdd(string data)
{
    stringstream str;
    string hasil = "";
    int jumlah = 0;
    int carry = 0;
    
    for(int i=0; i<data.length(); i++)
    {
        jumlah = carry + (int) (data.at(i) - '0' + data.at(data.length()-1-i) - '0');
        hasil += (jumlah%10 + '0');
        carry = jumlah/10;
    }
    
    if(carry!=0)
        hasil += carry + '0';
    return hasil;
}

bool isPalindrom(string x)
{
    int i = 0;
    int j = x.length()-1;
    
    while(i<j)
    {
        if(x.at(i) != x.at(j))
            return false;
        i++;
        j--;
    }
    
    return true;
}
