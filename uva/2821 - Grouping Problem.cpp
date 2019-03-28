#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int left = 0;
    int right = 0;
    int n = 0;
    int weight = 0;
    int pL = 0, pR = 0;
    bool dirLeft = true;
    
    vector<int> data;
    
    while(true)
    {
        scanf("%d", &n);
        if(n == 0)
            break;
        
        data.clear();
        data.reserve(n);
        for(int i = 0; i < n; i++)
        {
            scanf("%d", &weight);
            data.push_back(weight);
        }
        sort(data.begin(), data.end());
                
        left = right = 0;
        pL = 0;
        pR = n-1;
        dirLeft = true;
        
        while(!(pL>pR))
        {
            if(dirLeft)
            {
                if(left < right)
                    left += data.at(pL);
                else
                    right += data.at(pL);
                pL++;
            }
            else
            {
                if(left < right)
                    left += data.at(pR);
                else
                    right += data.at(pR);
                pR--;
            }
            dirLeft = !dirLeft;
        }
        
        if(left > right)
            printf("%d\n", left - right);
        else
            printf("%d\n", right - left);
        
    }
    
    return 0;
}
