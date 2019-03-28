#include <cstdio>
#include <map>
using namespace std;
int main()
{
    char *dvorak = "~!@#QJLMFP?{}$%^>ORSUYB:+|&*(AEHTDCK_)ZX<INWVG\"`123qjlmfp/[]456.orsuyb;=\\789aehtdck-0zx,inwvg\' \n";
    char *qwerty = "~!@#$%^&*()_+QWERTYUIOP{}|ASDFGHJKL:\"ZXCVBNM<>?`1234567890-=qwertyuiop[]\\asdfghjkl;\'zxcvbnm,./ \n";
    map<char,char> x;
    int i;
    for(i=0;qwerty[i]!='\0';i++)
        x[qwerty[i]]=dvorak[i];
    char y[1001];
    char z;
    while((z=getchar())!=EOF)
    {
        putchar(x[z]);
    }
    return 0;
}
