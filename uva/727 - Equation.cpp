#include <cstdio>
#include <stack>
#include <queue>

using namespace std;

int level(char c)
{
    switch(c)
    {
        case '*':
            return 4;
        case '/':
            return 4;
        case '+':
            return 2;
        case '-':
            return 2;
        default:
            return 0;
    }
}

int main()
{
    int t=1;
    char s[8];
    scanf("%d\n",&t);
    while(t--)
    {
        stack<char> st;
        queue<char> res;
//        do{
//            gets(s);
//            printf("debug: %s\n",s);
//        }while(s[0]!='\0');

//        do
        while(gets(s))
        {
            if(!s[0])
                break;
            if(s[0]>='0' && s[0]<='9')
                res.push(s[0]);
            else if(s[0] == ')')
            {
                while(st.top()!='(')
                      res.push(st.top()),st.pop();
                st.pop();
            }
            else if(s[0] == '(')
                st.push(s[0]);
//            else if(st.empty() || level(s[0])>level(st.top()))
//                st.push(s[0]);
            else
            {
                while(!st.empty() && level(st.top())>=level(s[0]))
                {
                    res.push(st.top());
                    st.pop();
                }
                st.push(s[0]);
            }
//
//            printf("debug: %s\n",s);
//        } while(s[0]!='\0');
        }

//        printf("%d %d\n",res.empty(),st.empty());
        while(!st.empty())
        {
            res.push(st.top());
            st.pop();
        }

        while(!res.empty())
        {
            putchar(res.front());
            res.pop();
        }
        putchar('\n');
        if(t)
            puts("");
    }
    return 0;
}
