#include <iostream>

double Vms(double a) {
    return a * (1000.0 / 3600);
}

double meetTime(double x, double y, double z) {
    return z * 1000 / (Vms(x) + Vms(y));
}

int main() {
    double kmh1, kmh2, km;

    std::cout << "First car speed (km/h): ";
    std::cin >> kmh1;
    std::cout << "Second car speed (km/h): ";
    std::cin >> kmh2;
    std::cout << "Distance (km): ";
    std::cin >> km;
    std::cout << std::endl;
    std::cout << "The cars will meet in " << meetTime(kmh1, kmh2, km) << " seconds.\n";

    return 0;
}
