#include <iostream>

int main()
{
    uint_fast64_t n; // Intermediate numbers may exceed 2^32 - 1.
    std::cin >> n;
    while (n != 1) {
        std::cout << n << ' ';
        n = (n % 2 == 0) ? (n / 2) : (3 * n + 1);
    }
    std::cout << n << '\n';
}
