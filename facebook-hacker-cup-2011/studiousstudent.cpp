#include <iostream>
#include <algorithm>

using namespace std;

bool cmp(string a, string b) {
   return (a+b) < (b+a);
}
   
int main()
{
   int a,b,c,i;
   string s[1000];
   cin>>a;
   while(a--)
   {
      cin>>b;
      for(i=0;i<b;i++)
         cin>>s[i];
      sort(s,s+b, cmp);
      for(i=0;i<b;i++)
         cout<<s[i];
      cout<<endl;
   }      
   return 0;
}   
