#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cstdlib>
#include <cmath>

using namespace std;

#define MAX 10

int currentL;
char C[MAX+1];
char A[MAX+1], B[MAX+1];
int lenA;
int lenB;

int manl(int i)
{
     if (i == currentL)
     {
           C[i] = '\0';
           if ((strcmp(C, A) <= 0))
            return 1; 
     }
     else if(i>currentL)
     {
        return 0;
     }
     else
     {
         int m = 0;
         for (char c = 'A'; c <= 'J'; c++)
             if ((i == 0) || (abs(c-C[i-1]) > 1))
             {
                   C[i] = c;
                   m += manl(i+1);
             }
         return m;          
     }
     return 0;
}

int manr(int i)
{
     if (i == currentL)
     {
           C[i] = '\0';
           if ((strcmp(C, B) < 0))
            return 1; 
     }
     else if(i>currentL)
     {
        return 0;
     }
     else
     {
         int m = 0;
         for (char c = 'A'; c <= 'J'; c++)
             if ((i == 0) || (abs(c-C[i-1]) > 1))
             {
                   C[i] = c;
                   m += manr(i+1);
             }
         return m;          
     }
     return 0;
}

int getNum(char *res)
{
    char c;
    while(true)
    {
        c=getchar_unlocked();
        if(c==' ' || c=='\n') continue;
        else if(c==EOF)
            return 0;
        else break;
    }
    *res = c-'0';
    res++;
    while(true)
    {
        c = getchar_unlocked();
        if(c>='A' && c<='J') *res = c,res++;
        else break;
    }
    return 1;
}

void inline print( int *res)
{
    register  int  N = * res , rev, count = 0;
    rev = N;
    if (N == 0)
    {
          putchar_unlocked('0');
         putchar_unlocked('\n');
          return ;
    }
    while ((rev % 10) == 0)
    {
          count++;
          rev /= 10;
    }
    rev = 0;
    while (N != 0)
    {
          rev = (rev<<3) + (rev<<1) + N % 10;
          N /= 10;
    }
    while (rev != 0)
    {
          putchar_unlocked(rev%10 + '0');
          rev /= 10;
    }
    while (count--)
          putchar_unlocked('0');
    putchar_unlocked('\n');
    return ;
}


int main()
{ 
    int dp[7][MAX] = {0};
    
    for(int i=0;i<MAX;i++)
        dp[0][i] = 1;
    
    for(int i=1;i<6;i++)
    {
        for(char c='A';c<='J';c++){
            for(char C='A';C<='J';C++){
                if(abs(c-C) > 1){
                    dp[i][c-'A'] += dp[i-1][C-'A'];
                }
            }
        }
    }
    /*for(int i=0;i<6;i++){
        for(int j=0;j<10;j++)
            printf("%d ", dp[i][j]);
            puts("");
        }*/
    //while(scanf("%s%s",A,B)!=EOF){
    while(1){
        
        
        if(strcmp(A,B)==0){
            puts("0");
            continue;
        }
        int tut=0;
        lenA = strlen(A);
        lenB = strlen(B);
        
        int i=lenA-1;
        int j=A[0]-'A';
        /*for(int i=lenA-1;i<lenB;i++)
        {
            for(int j=0;j<10;j++)
                tut+=dp[i][j];
        }*/
        
        while(1){
            if(!getNum(A))
                break;
            getNum(B);
            if(i == lenB-1 && j==B[0]-'A')
                break;
            tut+=dp[i][j];
            j++;
            if(j>9){
                j=0;
                i++;
            }
        }
        currentL = lenA;
        C[0] = A[0];
        tut -= manl(1);
        
        currentL = lenB;
        C[0] = B[0];
        tut += manr(1);
        //mcnt = 0;
        int cnt = 0;
        /*for (int i = lenA; i <= lenB; i++)
        {
            currentL = i;        
            cnt += count(0);           
        }*/
        //printf("%d\n", mcnt);
        //printf("%d\n", tut);
        print(&tut);
        puts("");
        //printf("%d\n", cnt);
    }
    return 0;
}

