// NUMBER GUESSING GAME
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    // Seed random number generator
    srand(time(0));

    // Generate random number between 1 and 100
    int secretNumber = rand() % 100 + 1;
    int guess;
    int attempts = 0;

    cout << "====================================\n";
    cout << "       NUMBER GUESSING GAME\n";
    cout << "====================================\n";
    cout << "I have selected a number between 1 and 100.\n";
    cout << "Try to guess it!\n\n";

    do {
        cout << "Enter your guess: ";
        cin >> guess;
        attempts++;

        if (guess > secretNumber) {
            cout << "Too high! Try a smaller number.\n\n";
        }
        else if (guess < secretNumber) {
            cout << "Too low! Try a larger number.\n\n";
        }
        else {
            cout << "\nCongratulations! You guessed the number!\n";
            cout << "The number was: " << secretNumber << endl;
            cout << "Number of attempts: " << attempts << endl;
        }

    } while (guess != secretNumber);

    cout << "\nThanks for playing!\n";

    return 0;
}