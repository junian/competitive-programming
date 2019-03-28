//#include <cstdio>
#include <iostream>
#include <map>
#include <string>
using namespace std;
int main()
{
    map<string, string> m;
    char *a="aaaaa";
    string s(a);
    m["."] = "a";
//    printf("%s\n",m["."]);
    cout<<s;
    return 0;

}
