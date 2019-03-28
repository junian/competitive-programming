#include <iostream>
#include <string>
#include <stack>

#define MAX 101

using namespace std;

int main()
{
    
    char input[MAX];
    char rotate[MAX][MAX];
    
    stack<string> kumpulan;
    string temp;
    
    int i = 0, j = 0;
    int max_size = 0;
    
    for(i=0; i<MAX; i++)
    {
        input[i] = '\0';
        for(j=0; j<MAX; j++)
        {
            rotate[i][j] = ' ';
        }
    }
    
    while(cin.getline(input, MAX+1, '\n'))
    {
        kumpulan.push(input);
        temp = input;
        if(max_size<=temp.size())
        {
            max_size = temp.size();
        }
    }
    
    j = 0;
    
    while(!kumpulan.empty())
    {
        temp = kumpulan.top();
        kumpulan.pop();
        for(i = 0; i < temp.size(); i++)
        {
            rotate[i][j] = temp[i];
        }
        j++;
    }
    
    for(i = 0; i < max_size; i++)
    {
        rotate[i][j] = '\0';
    }
    
    for(i = 0; i< max_size; i++)
        cout << rotate[i] << endl;
        
    return 0;
    
}
