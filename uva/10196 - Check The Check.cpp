#include <cstdio>

void verhor(char board[8][8], int i, int j)
{
    int iter = 1;
    while(true)
    {
        if(i+iter>=8 || (board[i+iter][j] != '.' && board[i+iter][j] != '*'))
            break;
        board[i+iter][j] = '*';
        iter++;
    }

    iter = 1;
    while(true)
    {
        if(i-iter<0 || (board[i-iter][j] != '.' && board[i-iter][j] != '*'))
            break;
        board[i-iter][j] = '*';
        iter++;
    }

    iter = 1;
    while(true)
    {
        if(j+iter>=8 || (board[i][j+iter] != '.' && board[i][j+iter] != '*'))
            break;
        board[i][j+iter] = '*';
        iter++;
    }

    iter = 1;
    while(true)
    {
        if(j-iter<0 || (board[i][j-iter] != '.' && board[i][j-iter] != '*'))
            break;
        board[i][j-iter] = '*';
        iter++;
    }
}

void diagonal(char board[8][8], int i, int j)
{
    int iter = 1;
    while(true)
    {
        if(i+iter>=8 || j+iter>=8 || (board[i+iter][j+iter] != '.' && board[i+iter][j+iter] == '*'))
            break;
        board[i+iter][j+iter] = '*';
        iter++;
    }

    iter = 1;
    while(true)
    {
        if(i+iter>=8 || j-iter<0 || (board[i+iter][j-iter] != '.' && board[i+iter][j-iter] == '*'))
            break;
        board[i+iter][j-iter] = '*';
        iter++;
    }

    iter = 1;
    while(true)
    {
        if(i-iter<0 || j+iter>=8 || (board[i-iter][j+iter] != '.' && board[i-iter][j+iter] == '*'))
            break;
        board[i-iter][j+iter] = '*';
        iter++;
    }

    iter = 1;
    while(true)
    {
        if(i-iter<0 || j-iter<0 || (board[i-iter][j-iter] != '.' && board[i-iter][j-iter] == '*'))
            break;
        board[i-iter][j-iter] = '*';
        iter++;
    }
}

void king(char board[8][8], int i, int j)
{

int main()
{
    char board_w[8][8];
    char board[8][8];
    char board_b[8][8];
    char chr;
    int countStar, i, j;
    int bi, bj, wi, wj;

    while(true)
    {
        countStar = 0;

        for(i=0; i<8; i++)
        {
            for(j=0; j<8; j++)
            {
                scanf("%c", &chr);
                board[i][j] = chr;
                if(chr == '.')
                {
                    board_b[i][j] = chr;
                    board_w[i][j] = chr;
                    countStar++;
                }
                else if(chr == 'K')
                {
                    board_b[i][j] = chr;
                    board_w[i][j] = '.';
                    wi = i;
                    wj = j;
                }
                else if(chr == 'k')
                {
                    board_b[i][j] = '.';
                    board_w[i][j] = chr;
                    bi = i;
                    bj = j;
                }
                else if(chr == 'P' || chr == 'R' || chr == 'B' || chr == 'Q' || chr == 'N')
                {
                    board_b[i][j] = chr;
                    board_w[i][j] = '*';
                }
                else
                {
                    board_b[i][j] = '*';
                    board_w[i][j] = chr;
                }
            }
        }

        if(countStar==64)
            break;

        for(i=0; i<8; i++)
        {
            for(j=0; j<8; j++)
            {
                switch(board[i][j])
                {
                    case 'P':
                        if(i-1>=0 && j-1>=0 && board_b[i-1][j-1] == '.')
                            board_b[i-1][j-1] = '*';
                        if(i-1>=0 && j+1<8 && board_b[i-1][j+1] == '.')
                            board_b[i-1][j+1] = '*';
                        break;
                    case 'p':
                        if(i+1<8 && j-1>=0 && board_w[i+1][j-1] == '.')
                            board_w[i+1][j-1] = '*';
                        if(i+1<8 && j+1<8 && board_w[i+1][j+1] == '.')
                            board_w[i+1][j+1] = '*';
                        break;
                    case 'R':
                        verhor(board_b, i, j);
                        break;
                    case 'r':
                        verhor(board_w, i, j);
                        break;
                    case 'B':
                        diagonal(board_b, i, j);
                        break;
                    case 'b':
                        diagonal(board_w, i, j);
                        break;
                    case 'Q':
                        verhor(board_b, i, j);
                        diagonal(board_w, i, j);
                        break;
                    case 'q':
                        verhor(board_w, i, j);
                        diagonal(board_w, i, j);
                        break;
                    default:
                        break;
                }
            }
        }

    }
    return 0;
}
