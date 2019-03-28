#include <cstdio>
#include <stack>
using namespace std;
int main()
{
    int n=0,i;
    char s[256],x;
    bool r;
    while((x=getchar())!='\n')
        n=n*10+(x-'0');
    while(n--)
    {
        i=0;
        while((x=getchar())!='\n')
            s[i++]=x;
        s[i]='\0';
        stack<char> st;
        r=true;
        for(i=0;s[i]!='\0';i++)
        {
            if(s[i]==']')
                if(st.empty() || st.top()!='[')
                {
                    r=false;
                    break;
                }
                else
                    st.pop();
            else if(s[i]==')')
                if(st.empty() || st.top()!='(')
                {
                    r=false;
                    break;
                }
                else
                    st.pop();
            else if(s[i]=='(' || s[i]=='[')
                st.push(s[i]);
        }

        if(r==true && st.empty())
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
