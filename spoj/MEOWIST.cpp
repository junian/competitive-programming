#include <cstdio>
#include <cstdlib>
#include <cstring>

typedef struct people
{
    int age;
    char name[11];
};

int compare (const void * a, const void * b)
{
    people*x=(people*)a;
    people*y=(people*)b;
    if(x->age == y->age)
    {
        return(strcmp(x->name,y->name));
    }
    return (y->age - x->age);
}

int main()
{
    people a[10000];
    int n=0,i;
    while(scanf("%s %d",a[n].name,&a[n].age)!=EOF)
    {
        n++;
    }
    qsort(a, n, sizeof(people), compare);
    for(i=0;i<n;i++)
    {
        printf("%s\n",a[i].name);
    }
    return 0;
}
