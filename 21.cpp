#include <cstdlib>
#include <cstdio>
#include <cstring>

int compare(const void *a, const void *b)
{
    char * aa = (char*) a;
    char * bb = (char*) b;

    char as = *aa >= 'A' && *aa <= 'Z' ? *aa - 'A' + 'a' : *aa;
    char bs = *bb >= 'A' && *bb <= 'Z' ? *bb - 'A' + 'a' : *bb;

    if(as < bs) return -1;
    if(as > bs) return 1;
    if(as == bs)
    {
        if(*aa == *bb) return 0;
        if(*aa > *bb) return -1;
    }
    return 1;
}

int main()
{
    char kal[256];
    int t;

    fflush(stdin);
    scanf("%d", &t);

    while(t>0)
    {
        t--;
        fflush(stdin);
        gets(kal);
        qsort(kal, strlen(kal), sizeof(char), compare);
        printf("%s\n", kal);
    }

    return 0;
}
