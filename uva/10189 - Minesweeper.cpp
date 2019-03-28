#include <cstdio>

int main()
{
    int n, m, x = 0, angka;
    char board[101][101];
    int i, j;

    while(true)
    {
        x++;
        scanf("%d %d", &n, &m);

        if(n==0 && m==0)
            break;

        if(x>1)
            printf("\n");

        for(i=0; i<n; i++)
        {
            scanf("%s", board[i]);
        }

        for(i=0; i<n; i++)
        {
            for(j=0; j<m; j++)
            {
                if(board[i][j] == '*')
                    continue;
                angka = 0;
                if(i-1>=0 && board[i-1][j] == '*')
                    angka++;
                if(i-1>=0 && j+1<m && board[i-1][j+1] == '*')
                    angka++;
                if(j+1<m && board[i][j+1] == '*')
                    angka++;
                if(i+1<n && j+1<m && board[i+1][j+1] == '*')
                    angka++;
                if(i+1<n && board[i+1][j] == '*')
                    angka++;
                if(i+1<n && j-1>=0 && board[i+1][j-1] == '*')
                    angka++;
                if(j-1>=0 && board[i][j-1] == '*')
                    angka++;
                if(i-1>=0 && j-1>=0 && board[i-1][j-1] == '*')
                    angka++;
                board[i][j] = angka + '0';
            }
        }

        printf("Field #%d:\n", x);
        for(i=0; i<n; i++)
            puts(board[i]);
    }

    return 0;
}
