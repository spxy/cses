#include <cstdint>
#include <iostream>

int main()
{
    std::uint_fast32_t n; // 1 <= n <= 10^6.
    std::cin >> n;

    if (n == 2 || n == 3) {
        std::cout << "NO SOLUTION\n";
        return 0;
    }

    for (std::uint_fast32_t k = 2; k <= n; k += 2) {
        std::cout << k << ' ';
    }

    for (std::uint_fast32_t k = 1; k <= n; k += 2) {
        std::cout << k << ' ';
    }

    std::cout << '\n';
}
