#include <iostream>

double circleArea(double a) {
    const double pi = 3.14159;
    return pi * (a * a);
}

int main() {
    double r1;
    double r2;

    std::cout << "Enter outer circle radius: ";
    std::cin >> r1;
    std::cout << "Enter inner circle radius: ";
    std::cin >> r2;

    if (r1 <= r2) {
        std::cout << "Outer radius must be larger than inner radius!";
    }

    std::cout << "Circle area: " << circleArea(r1) - circleArea(r2) + 2 * circleArea(r2 / 2);

    return 0;
}
