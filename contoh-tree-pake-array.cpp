#include <cstdio>

#define LEFTCHILD 2*i+1
#define PARENT i/2

int main()
{
    int tree[1000];
    tree[0] = 1;
    int i = 0;
    tree[LEFTCHILD] = 2;
    tree[LEFTCHILD+1] = 3;
    i++;
    tree[PARENT] = 0;
    printf("%d %d %d\n",tree[0],tree[1],tree[2]);
    return 0;
}
