#include <cstdio>
#include <cstdlib>
#include <ctime>

#define MAX 10000

int main()
{
    srand(time(NULL));
    int n, k, i, hire;
    int score[MAX];
    int best;

    printf("input n: ");
    scanf("%d",&n);
    printf("input k: ");
    scanf("%d",&k);

    for(i=0;i<n;i++)
    {
        printf("input score-%d: ", i+1);
        scanf("%d",&score[i]);
    }

//    for(i=0;i<n;i++)
//    {
//        int a = rand()%n;
//        int b = rand()%n;
//        int tmp = score[a];
//        score[a] = score[b];
//        score[a] = score[tmp];
//    }

    best = 0;

    for(i=1;i<k;i++)
        if(score[i] > score[best])
            best = i;

    hire = n-1;
    for(i=k;i<n;i++)
        if(score[i]>score[best])
        {
            hire = i;
            break;
        }

    printf("orang ke-%d dengan skor %d di-hire\n",hire+1,score[hire]);

    return 0;
}
