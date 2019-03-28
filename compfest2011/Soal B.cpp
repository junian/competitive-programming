#include <cstdio>
#include <stack>
#include <vector>

using namespace std;

int main()
{
    int t;

    scanf("%d\n",&t);
    
    char s[256];

    while(t--)
    {
        stack< char > st;
        vector< char > sol;
        gets(s);
        for(int i=0; s[i]!='\0';i++)
        {
            if(s[i] == '~')
            {
                if(!st.empty() && st.top() == '~')
                    st.pop();
                else st.push(s[i]);
            }
            else if(s[i] != '^')
            {
                if(!st.empty() && st.top() == '~')
                {
                    st.pop();
                    if(s[i] == 'S')
                        sol.push_back('B');
                    else if(s[i] == 'B')
                        sol.push_back('S');
                    else
                        sol.push_back(~s[i]);

                }
                else
                    sol.push_back(s[i]);
                    
            }
        }
        bool benar = true;
        bool mungkin = false;
        for(int j=0;j<sol.size(); j++)
        {
            //printf("%d %d\n",s[j],~(s[j]));
            if(benar && sol[j] == 'S')
            {
                benar = false;
            }
            else if(benar && sol[j] !='S' && sol[j]!='B')
            {
                for(int k=j+1;k<sol.size();k++)
                    if(sol[k] == ~sol[j])
                    {
//                        puts("sss");
                        benar = false;
                    }
                if(benar)
                    mungkin = true;
            }
        }
                
        if(benar && !mungkin)
            puts("benar");
        else if(benar == false)
            puts("salah");
        else
            puts("mungkin");
            
    }
    return 0;
}
