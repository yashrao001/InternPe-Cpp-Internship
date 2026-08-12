//TIC TAC TOE 
#include <iostream>
#include <cstdlib>

using namespace std;

// Display the game board
void displayBoard(char board[])
{
    cout << "\n";
    cout << "       TIC TAC TOE\n";
    cout << "=========================\n\n";

    cout << "       |       |       \n";
    cout << "    " << board[0] << "  |   " << board[1] << "   |   " << board[2] << "\n";
    cout << "       |       |       \n";

    cout << "-------+-------+-------\n";

    cout << "       |       |       \n";
    cout << "    " << board[3] << "  |   " << board[4] << "   |   " << board[5] << "\n";
    cout << "       |       |       \n";

    cout << "-------+-------+-------\n";

    cout << "       |       |       \n";
    cout << "    " << board[6] << "  |   " << board[7] << "   |   " << board[8] << "\n";
    cout << "       |       |       \n";

    cout << "=========================\n";
}

// Check if a player has won
bool checkWin(char board[], char player)
{
    // Rows
    if (board[0] == player && board[1] == player && board[2] == player)
        return true;

    if (board[3] == player && board[4] == player && board[5] == player)
        return true;

    if (board[6] == player && board[7] == player && board[8] == player)
        return true;

    // Columns
    if (board[0] == player && board[3] == player && board[6] == player)
        return true;

    if (board[1] == player && board[4] == player && board[7] == player)
        return true;

    if (board[2] == player && board[5] == player && board[8] == player)
        return true;

    // Diagonals
    if (board[0] == player && board[4] == player && board[8] == player)
        return true;

    if (board[2] == player && board[4] == player && board[6] == player)
        return true;

    return false;
}

// Check if the board is full
bool checkDraw(char board[])
{
    for (int i = 0; i < 9; i++)
    {
        if (board[i] >= '1' && board[i] <= '9')
            return false;
    }

    return true;
}

int main()
{
    char playAgain;

    do
    {
        // Create board
        char board[9] = {
            '1', '2', '3',
            '4', '5', '6',
            '7', '8', '9'
        };

        char currentPlayer = 'X';
        int position;

        cout << "\n";
        cout << "=====================================\n";
        cout << "          TIC TAC TOE GAME\n";
        cout << "=====================================\n";

        cout << "\nPlayer 1 : X\n";
        cout << "Player 2 : O\n";

        cout << "\nBoard positions:\n";

        displayBoard(board);

        // Game loop
        while (true)
        {
            cout << "\nPlayer " << currentPlayer << "'s turn.";
            cout << "\nChoose a position (1-9): ";
            cin >> position;

            // Check invalid input
            if (cin.fail())
            {
                cin.clear();
                cin.ignore(1000, '\n');

                cout << "\nInvalid input!";
                cout << "\nPlease enter a number from 1 to 9.\n";

                continue;
            }

            // Check position range
            if (position < 1 || position > 9)
            {
                cout << "\nInvalid position!";
                cout << "\nChoose a number between 1 and 9.\n";

                continue;
            }

            // Convert position to array index
            int index = position - 1;

            // Check if position is already occupied
            if (board[index] == 'X' || board[index] == 'O')
            {
                cout << "\nThat position is already taken!";
                cout << "\nChoose another position.\n";

                continue;
            }

            // Place player's symbol
            board[index] = currentPlayer;

            // Display updated board
            displayBoard(board);

            // Check for winner
            if (checkWin(board, currentPlayer))
            {
                cout << "\n=====================================\n";
                cout << "       PLAYER " << currentPlayer << " WINS!\n";
                cout << "=====================================\n";

                break;
            }

            // Check for draw
            if (checkDraw(board))
            {
                cout << "\n=====================================\n";
                cout << "              DRAW!\n";
                cout << "=====================================\n";

                break;
            }

            // Switch player
            if (currentPlayer == 'X')
                currentPlayer = 'O';
            else
                currentPlayer = 'X';
        }

        // Ask to play again
        cout << "\nDo you want to play again? (y/n): ";
        cin >> playAgain;

    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "\n=====================================\n";
    cout << "        THANKS FOR PLAYING!\n";
    cout << "=====================================\n";

    return 0;
}

