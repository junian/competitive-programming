#include <iostream>
#include <set>

using namespace std;

int fact(int i)
{
    if(i==0 || i==1)
        return 1;
    return i*fact(i-1);
}

int main()
{
    set<string> data;
    string str;
    int t, max, count;
    char temp;
    cin >> t;
    while(t>0)
    {
        t--;
        cin >> str;
        data.clear();
        count = 0;
        max = fact(str.size());
        for(int i=0; i<max; i++)
        {
            temp = str[count];
            str[count] = str[count+1];
            str[count+1] = temp;
            data.insert(str);
            count = (count+1)%(str.size()-1);
        }
        for(set<string>::iterator iter=data.begin(); iter!=data.end(); iter++)
            cout << *iter << endl;
    }
    return 0;
}
