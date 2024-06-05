#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(0));

    int secretNumber = rand() % 100 + 1;
    int guess;
    int attempts = 0;
    clock_t start_time, end_time;

    cout << "Welcome to the Number Guessing Game!" << endl;
    cout << "I have selected a number between 1 and 100. Try to guess it!" << endl;

    do {
        cout << "Enter your guess: ";
        cin >> guess;

        start_time = clock();

        if (guess < secretNumber) {
            cout << "Too low!" << endl;
        } else if (guess > secretNumber) {
            cout << "Too high!" << endl;
        } else {
            cout << "Congratulations! You guessed the number in " << attempts + 1 << " attempts!" << endl;
            break;
        }

        end_time = clock();

        double time_taken = double(end_time - start_time) / CLOCKS_PER_SEC;

        int randomDelay = rand() % 100 + 1;
        time_taken += randomDelay / 100.0;

        if (time_taken > 5.0) {
            cout << "Time's up! You took too long to guess." << endl;
            break;
        }

        attempts++;
    } while (guess != secretNumber);

    if (attempts >= 5) {
        cout << "You've made " << attempts << " attempts. That was a tough one!" << endl;
    }

    return 0;
}