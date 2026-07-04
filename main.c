#include <stdio.h>

void printBoard(char[3][3]);

void printBoard(char arr[3][3])
{
    printf("   |   |   \n");
    printf(" %c | %c | %c \n", arr[0][0], arr[0][1], arr[0][2]);
    printf("___|___|___\n");

    printf("   |   |   \n");
    printf(" %c | %c | %c \n", arr[1][0], arr[1][1], arr[1][2]);
    printf("___|___|___\n");

    printf("   |   |   \n");
    printf(" %c | %c | %c \n", arr[2][0], arr[2][1], arr[2][2]);
    printf("   |   |   \n");
}

char checkWinner(char b[3][3]);

// This function returns 'X' if X won, 'O' if O won, or 0 if no winner yet.
char checkWinner(char b[3][3])
{
    // Check Rows and Columns
    for (int i = 0; i < 3; i++)
    {
        // Rows
        if (b[i][0] == b[i][1] && b[i][1] == b[i][2])
            return b[i][0];
        // Columns
        if (b[0][i] == b[1][i] && b[1][i] == b[2][i])
            return b[0][i];
    }
    // Check Diagonals
    if (b[0][0] == b[1][1] && b[1][1] == b[2][2])
        return b[0][0];
    if (b[0][2] == b[1][1] && b[1][1] == b[2][0])
        return b[0][2];

    return 0; // No winner
}

void repetation(int *, char board[3][3], char);

void repetation(int *a, char board[3][3], char c)
{
    int row, col;
    while (1)
    {
        if (*a > 9 || *a <0)
        {
            printf("You entered a invalid number. Try Again :");
            scanf("%d", a);
        }
        else
        {

            row = (*a - 1) / 3;
            col = (*a - 1) - row * 3;
            if (board[row][col] == 'X' || board[row][col] == 'O')
            {
                printf("You're trying to enter on a preoccupied box. Enter Again :");
                scanf("%d", a);
            }
            else
            {
                board[row][col] = c;
                break;
            }
        }
    }
}

int main()
{
    char winner;
    int player1;
    int player2;
    int turn = 0;
    char board[3][3] = {
        {'1', '2', '3'},
        {'4', '5', '6'},
        {'7', '8', '9'}};

    printBoard(board);

    while (1)
    {
        // Taking input from player 1
        printf("Player 1(X) please enter the box number you would like to play :");
        scanf("%d", &player1);
        turn++;
        // Converting the input of player 1 and redrawing the board with X
        repetation(&player1, board, 'X');
        printBoard(board);

        // Checking winner
        winner = checkWinner(board);
        if (winner == 'X' || winner == 'O')
        {
            printf("Player %c wins!\n", winner);
            break;
        }

        // checking for break
        if (turn == 9)
        {
            printf("It's a draw!\n");
            break;
        }
        // Taking input from player 2
        printf("Player 2(O) please enter the box number you would like to play :");
        scanf("%d", &player2);
        turn++;
        // Converting the input of player 2 and redrawing the board with O
        repetation(&player2, board, 'O');
        printBoard(board);
        // Checking winner
        winner = checkWinner(board);
        if (winner == 'X' || winner == 'O')
        {
            printf("Player %c wins!\n", winner);
            break;
        }
    }

    return 0;
}