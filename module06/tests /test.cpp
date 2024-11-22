#include <iostream>
#include <limits>
#include <iomanip>
#include <cmath>

void compareEpsilon(double a, double b) {
    double epsilon = std::numeric_limits<double>::epsilon();
    double epsilon_100 = epsilon * 100;
    
    std::cout << std::fixed << std::setprecision(16);
    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;
    std::cout << "Différence absolue = " << std::abs(a - b) << std::endl;
    std::cout << "epsilon      = " << epsilon << std::endl;
    std::cout << "epsilon * 100= " << epsilon_100 << std::endl;
    
    std::cout << "Avec epsilon simple     : " 
              << (std::abs(a - b) <= epsilon ? "Considéré comme égal" : "Considéré comme différent") 
              << std::endl;
    
    std::cout << "Avec epsilon * 100      : " 
              << (std::abs(a - b) <= epsilon_100 ? "Considéré comme égal" : "Considéré comme différent") 
              << std::endl;
    
    std::cout << "-------------------" << std::endl;
}

int main() {
    // Cas 1 : Nombres très proches
    compareEpsilon(42.0, 42.0000000000000001);
    
    // Cas 2 : Nombres légèrement différents
    compareEpsilon(42.0, 42.00001);
    
    return 0;
}