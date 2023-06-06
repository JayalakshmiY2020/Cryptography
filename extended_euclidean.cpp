#include <iostream>
#include <tuple>

std::tuple<int, int, int> extended_euclidean_algorithm(int a, int b) {
    if (b == 0) {
        return std::tuple<int, int, int>(a, 1, 0);
    }

    int gcd, x1, y1;
    std::tie(gcd, x1, y1) = extended_euclidean_algorithm(b, a % b);
    int x = y1;
    int y = x1 - (a / b) * y1;

    return std::tuple<int, int, int>(gcd, x, y);
}

int find_modular_inverse(int a, int m) {
    int gcd, x, y;
    std::tie(gcd, x, y) = extended_euclidean_algorithm(a, m);
    if (gcd != 1) {
        throw std::runtime_error("Inverse does not exist.");
    }

    return (x % m + m) % m;
}

int main() {
    int number, modulus;

    std::cout << "Enter a number to find the inverse: ";
    std::cin >> number;

    std::cout << "Enter the number whose modulus is to be found: ";
    std::cin >> modulus;

    int inverse = find_modular_inverse(number, modulus);
    std::cout << "Modular inverse of " << number << " mod " << modulus << " is: " << inverse << std::endl;

    return 0;
}
