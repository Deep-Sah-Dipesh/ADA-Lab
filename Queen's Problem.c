#include <stdio.h>
#include <stdbool.h>

#define MAX_N 10

void printSolution(int board[MAX_N][MAX_N], int N)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("%c ", board[i][j] ? 'Q' : '.');
        }
        printf("\n");
    }
}

bool isSafe(int board[MAX_N][MAX_N], int row, int col, int N)
{
    for (int i = 0; i < col; i++)
    {
        if (board[row][i])
        {
            return false;
        }
    }

    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j])
        {
            return false;
        }
    }

    for (int i = row, j = col; i < N && j >= 0; i++, j--)
    {
        if (board[i][j])
        {
            return false;
        }
    }

    return true;
}

bool solveNQueens(int board[MAX_N][MAX_N], int col, int N)
{
    if (col >= N)
    {
        return true;
    }

    for (int i = 0; i < N; i++)
    {
        if (isSafe(board, i, col, N))
        {
            board[i][col] = 1;

            if (solveNQueens(board, col + 1, N))
            {
                return true;
            }
            board[i][col] = 0;
        }
    }

    return false;
}

void solveNQueensWrapper(int N)
{
    int board[MAX_N][MAX_N] = {0};

    if (solveNQueens(board, 0, N))
    {
        printf("Solution found:\n");
        printSolution(board, N);
    }
    else
    {
        printf("Solution does not exist for N = %d\n", N);
    }
}

int main()
{
    int N;

    printf("Enter the size of the chessboard (N): ");
    scanf("%d", &N);

    if (N <= 0 || N > MAX_N)
    {
        printf("Invalid input for N. Please enter a number between 1 and %d.\n", MAX_N);
        return 1;
    }
    solveNQueensWrapper(N);
    return 0;
}
