#include<iostream>

using namespace std;

string decode(string kar);
char getChar(char chr);

const string key = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";
                  
int main()
{
    string kar = "";
    
    while(getline(cin, kar))
    {
        cout<<decode(kar)<<endl;
    }
    
    return 0;
}

string decode(string kar)
{
    string hasil = "";
    for(int i=0; i<kar.length(); i++)
    {
        hasil += getChar(kar.at(i));
    } 
    return hasil;
}

char getChar(char chr)
{
    for(int i=1; i<key.length(); i++)
    {
        if(chr == key.at(i))
        {
            return key.at(i-1);
        }
    }
    return ' ';
}
