#include <cstdio>
#include <stack>
using namespace std;
int main()
{
    char x;
    int n=0,i=1;
    while(1)
    {
        x=getchar();
        if(x=='-')
            break;
        n=0;
        stack<char> s;
        if(x=='{')
            s.push(x);
        else if(x=='}')
        {
            s.push('{');
            n++;
        }
        while((x=getchar()),x!='\n'&&x!='\r')
        {
            if(x=='{')
                s.push(x);
            else if(!s.empty() && x=='}')
                s.pop();
            else if(x=='}')
            {
                s.push('{');
                n++;
            }
        }
        n+=(s.size()%2==0)?s.size()/2:s.size()/2+1;
        printf("%d. %d\n",i++,n);
    }
    return 0;
}
