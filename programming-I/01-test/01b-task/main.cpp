#include <iostream>

int main() {
    int n = 100000;
    int rev;

    std::cout << "The program outputs all six-digit palindromes.\n";
    do {
        rev = 0;
        for (int i = n; i > 0; i /= 10) {
            rev = rev * 10 + i % 10;
            if (n == rev) {
                std::cout << n << std::endl;
            }
        }
        n++;
    } while (n <= 999999);

    return 0;
}
