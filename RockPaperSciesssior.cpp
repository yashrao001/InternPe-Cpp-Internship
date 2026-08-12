// ROCK,PAPER,SCIESOR.
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    srand(time(0));

    int userChoice, computerChoice;
    int userScore = 0, computerScore = 0;
    char playAgain;

    cout << "====================================\n";
    cout << "       ROCK PAPER SCISSORS GAME\n";
    cout << "====================================\n";

    do {
        cout << "\nChoose your option:\n";
        cout << "1. Rock\n";
        cout << "2. Paper\n";
        cout << "3. Scissors\n";
        cout << "Enter your choice: ";
        cin >> userChoice;

        // Input validation
        if (userChoice < 1 || userChoice > 3) {
            cout << "Invalid choice! Please choose 1, 2, or 3.\n";
            continue;
        }

        // Computer chooses randomly
        computerChoice = rand() % 3 + 1;

        cout << "\nYou chose: ";
        if (userChoice == 1)
            cout << "Rock";
        else if (userChoice == 2)
            cout << "Paper";
        else
            cout << "Scissors";

        cout << "\nComputer chose: ";
        if (computerChoice == 1)
            cout << "Rock";
        else if (computerChoice == 2)
            cout << "Paper";
        else
            cout << "Scissors";

        // Determine winner
        if (userChoice == computerChoice) {
            cout << "\n\nIt's a DRAW!";
        }
        else if (
            (userChoice == 1 && computerChoice == 3) ||
            (userChoice == 2 && computerChoice == 1) ||
            (userChoice == 3 && computerChoice == 2)
        ) {
            cout << "\n\nYou WIN!";
            userScore++;
        }
        else {
            cout << "\n\nComputer WINS!";
            computerScore++;
        }

        // Display score
        cout << "\n----------------------------";
        cout << "\nYour Score     : " << userScore;
        cout << "\nComputer Score : " << computerScore;
        cout << "\n----------------------------";

        cout << "\n\nDo you want to play again? (y/n): ";
        cin >> playAgain;

    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "\n====================================\n";
    cout << "             FINAL RESULT\n";
    cout << "====================================\n";

    cout << "Your Score     : " << userScore << endl;
    cout << "Computer Score : " << computerScore << endl;

    if (userScore > computerScore)
        cout << "Congratulations! You are the WINNER! 🏆\n";
    else if (computerScore > userScore)
        cout << "Computer wins! Better luck next time!\n";
    else
        cout << "The match ended in a DRAW!\n";

    cout << "====================================\n";

    return 0;
}