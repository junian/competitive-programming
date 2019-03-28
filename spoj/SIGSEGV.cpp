#include <cstdio>
#include <cstdlib>

int main()
{
    int **tab=(int**)malloc(sizeof(int*)*999999999);
    for(int i=0;i<999999999;i++)
        tab[i]=(int*)malloc(sizeof(int)*999999999);
    return 0;
}
