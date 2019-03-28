#include <stdio.h>
#include <stdlib.h>

int compare (const void * a, const void * b)
{
  return ( *(int*)b - *(int*)a );
}

int main()
{
    int n, k, s;
    int total, i, box;
    int a[1001];

    scanf("%d %d %d", &n, &k, &s);
    total = k*s;
    for(i=0; i<n; i++)
        scanf("%d", &a[i]);
    qsort(a, n, sizeof(int), compare);
    box = 0;
    while(total>0)
    {
        total -= a[box];
        box++;
    }
    printf("%d\n", box);
    return 0;
}
