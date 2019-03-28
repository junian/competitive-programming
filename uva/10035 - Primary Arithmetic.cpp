#include <iostream>

using namespace std;

void cetakCarry(string x, string y);
int getCarry(string x, string y);

int main()
{
    string x = "";
    string y = "";
    
    while(cin>>x>>y)
    {
        if(x == "0" && y == "0")
            break;
        
        cetakCarry(x, y);
    }    
    
    return 0;
}

void cetakCarry(string x, string y)
{
    int carry = 0;
    
    if(x.size()<y.size())
    {
        while(x.size()!=y.size())
        {
            x = "0" + x;
        }
    }
    else
    {
        while(x.size()!=y.size())
        {
            y = "0" + y;
        }
    }
    
    carry = getCarry(x, y);
    
    if(carry == 0)
    {
        cout<<"No carry operation."<<endl;
    }
    else if(carry == 1)
    {
        cout<<"1 carry operation."<<endl;
    }
    else
    {
        cout<<carry<<" carry operations."<<endl;
    }
}

int getCarry(string x, string y)
{
    int carry = 0;
    int n = x.size()-1;
    int jumlah = 0;
    bool carried = false;
    
    while(n>=0)
    {   
        jumlah = (int) (x.at(n)-'0' + y.at(n)-'0');
        
        if(carried) 
            jumlah += 1;   
            
        if(jumlah>=10)
        {
            carry++;
            carried = true;
        }
        else{
            carried = false;
        }
        
        n--;
    }
    
    return carry;
}
