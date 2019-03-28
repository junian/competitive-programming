#include <stdio.h>
#include <stdlib.h>

int compare (const void * a, const void * b)
{
  return ( *(int*)b - *(int*)a );
}

int main()
{
    int t, n, i, tot;
    int hotm[1001];
    int hotf[1001];
    scanf("%d", &t);
    while(t>0)
    {
        t--;
        scanf("%d", &n);
        for(i=0; i<n; i++)
            scanf("%d", &hotm[i]);
        for(i=0; i<n; i++)
            scanf("%d", &hotf[i]);
        tot = 0;
        qsort(hotm, n, sizeof(int), compare);
        qsort(hotf, n, sizeof(int), compare);
        for(i=0; i<n; i++)
        {
            tot += hotm[i]*hotf[i];
        }
        printf("%d\n", tot);
    }
    return 0;
}
