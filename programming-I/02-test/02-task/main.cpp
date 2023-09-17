#include <iostream>

double calculatePrice(double a) {
    double price;

    if (a == 0) {
        price = 0;
    } else if (a <= 3) {
        price = 2;
    } else if (a > 19) {
        price = 10;
    } else {
        price = 2 + (a - 3) * (0.5);
    }
    return price;
}

int main() {
    int h;

    std::cout << "Enter hours parked: ";
    std::cin >> h;
    std::cout << "Price EUR: " << calculatePrice(h);

    return 0;
}
