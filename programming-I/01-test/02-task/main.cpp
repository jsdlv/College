#include <iostream>

int main() {
    int x;
    int n;

    time_t t;
    std::srand((unsigned) time(&t));
    x = std::rand() % 101;

    std::cout << "Guess the secret number between 1 and 100.\n";
    std::cout << "You have only 10 possibilities to win.\n";

    for (int i = 1; i <= 10; i++) {
        std::cout << "Enter your guess: ";
        std::cin >> n;
        if (n > x) {
            std::cout << "My secret number is lower.\n";
        } else if (n < x) {
            std::cout << "My secret number is higher.\n";
        } else {
            std::cout << "Congratulations, You guessed from " << i << " times!\n";
            return 0;
        }
    }
    std::cout << "Sorry, You loose, try again next time. The secret number was: " << x << "\n";

    return 0;
}
