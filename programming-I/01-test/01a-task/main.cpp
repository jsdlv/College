#include <iostream>

int main() {
    int number;
    int reverse = 0;

    std::cout << "The program checks whether the given number is a palindrome or not.\n";
    std::cout << "Please enter a number: ";
    std::cin >> number;

    for (int i = number; i != 0; i /= 10) {
        reverse = reverse * 10 + i % 10;
    }
    if (number == reverse) {
        std::cout << "The entered number is a palindrome.\n";
    } else {
        std::cout << "The number entered is not a palindrome.\n";
    }
    return 0;
}
