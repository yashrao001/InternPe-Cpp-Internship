// CONNECT FOUR GAME 
#include <iostream>

using namespace std;

const int ROWS = 6;
const int COLS = 7;

// Display the board
void displayBoard(char board[ROWS][COLS])
{
    cout << "\n";
    cout << "=========================================\n";
    cout << "              CONNECT FOUR\n";
    cout << "=========================================\n";

    for (int i = 0; i < ROWS; i++)
    {
        cout << "|";

        for (int j = 0; j < COLS; j++)
        {
            cout << " " << board[i][j] << " |";
        }

        cout << "\n";
        cout << "-----------------------------------------\n";
    }

    cout << "  1   2   3   4   5   6   7\n";
    cout << "=========================================\n";
}

// Drop a piece into a column
bool dropPiece(char board[ROWS][COLS], int column, char player)
{
    // Start from the bottom
    for (int row = ROWS - 1; row >= 0; row--)
    {
        if (board[row][column] == ' ')
        {
            board[row][column] = player;
            return true;
        }
    }

    return false;
}

// Check if a player has won
bool checkWin(char board[ROWS][COLS], char player)
{
    // Check horizontal
    for (int row = 0; row < ROWS; row++)
    {
        for (int col = 0; col <= COLS - 4; col++)
        {
            if (board[row][col] == player &&
                board[row][col + 1] == player &&
                board[row][col + 2] == player &&
                board[row][col + 3] == player)
            {
                return true;
            }
        }
    }

    // Check vertical
    for (int row = 0; row <= ROWS - 4; row++)
    {
        for (int col = 0; col < COLS; col++)
        {
            if (board[row][col] == player &&
                board[row + 1][col] == player &&
                board[row + 2][col] == player &&
                board[row + 3][col] == player)
            {
                return true;
            }
        }
    }

    // Check diagonal: top-left to bottom-right
    for (int row = 0; row <= ROWS - 4; row++)
    {
        for (int col = 0; col <= COLS - 4; col++)
        {
            if (board[row][col] == player &&
                board[row + 1][col + 1] == player &&
                board[row + 2][col + 2] == player &&
                board[row + 3][col + 3] == player)
            {
                return true;
            }
        }
    }

    // Check diagonal: bottom-left to top-right
    for (int row = 3; row < ROWS; row++)
    {
        for (int col = 0; col <= COLS - 4; col++)
        {
            if (board[row][col] == player &&
                board[row - 1][col + 1] == player &&
                board[row - 2][col + 2] == player &&
                board[row - 3][col + 3] == player)
            {
                return true;
            }
        }
    }

    return false;
}

// Check if board is full
bool checkDraw(char board[ROWS][COLS])
{
    for (int col = 0; col < COLS; col++)
    {
        if (board[0][col] == ' ')
        {
            return false;
        }
    }

    return true;
}

// Clear the board
void initializeBoard(char board[ROWS][COLS])
{
    for (int row = 0; row < ROWS; row++)
    {
        for (int col = 0; col < COLS; col++)
        {
            board[row][col] = ' ';
        }
    }
}

int main()
{
    char playAgain;

    do
    {
        char board[ROWS][COLS];

        initializeBoard(board);

        char currentPlayer = 'X';
        int column;

        cout << "\n";
        cout << "#########################################\n";
        cout << "#                                       #\n";
        cout << "#          CONNECT FOUR GAME            #\n";
        cout << "#                                       #\n";
        cout << "#########################################\n";

        cout << "\nPlayer 1 : X";
        cout << "\nPlayer 2 : O\n";

        cout << "\nHow to play:";
        cout << "\nDrop your piece into a column.";
        cout << "\nConnect four pieces horizontally, vertically";
        cout << "\nor diagonally to win.\n";

        displayBoard(board);

        // Main game loop
        while (true)
        {
            cout << "\nPlayer " << currentPlayer << "'s turn.";
            cout << "\nChoose a column (1-7): ";
            cin >> column;

            // Check invalid input
            if (cin.fail())
            {
                cin.clear();
                cin.ignore(1000, '\n');

                cout << "\nInvalid input!";
                cout << "\nPlease enter a number from 1 to 7.\n";

                continue;
            }

            // Convert to array index
            column--;

            // Check column range
            if (column < 0 || column >= COLS)
            {
                cout << "\nInvalid column!";
                cout << "\nChoose a column from 1 to 7.\n";

                continue;
            }

            // Try to drop piece
            if (!dropPiece(board, column, currentPlayer))
            {
                cout << "\nThat column is full!";
                cout << "\nChoose another column.\n";

                continue;
            }

            // Display board
            displayBoard(board);

            // Check winner
            if (checkWin(board, currentPlayer))
            {
                cout << "\n=========================================\n";
                cout << "          PLAYER " << currentPlayer << " WINS!\n";
                cout << "=========================================\n";

                break;
            }

            // Check draw
            if (checkDraw(board))
            {
                cout << "\n=========================================\n";
                cout << "               DRAW!\n";
                cout << "=========================================\n";

                break;
            }

            // Change player
            if (currentPlayer == 'X')
            {
                currentPlayer = 'O';
            }
            else
            {
                currentPlayer = 'X';
            }
        }

        // Replay
        cout << "\nDo you want to play again? (y/n): ";
        cin >> playAgain;

    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "\n=========================================\n";
    cout << "          THANKS FOR PLAYING!\n";
    cout << "=========================================\n";

    return 0;
}

