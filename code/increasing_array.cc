#include <algorithm>
#include <cstdint>
#include <iostream>

int main()
{
    std::uint_fast32_t n; // 1 <= n <= 200000.
    std::uint_fast32_t x; // 1 <= x <= 10^9.
    std::uint_fast32_t max_x = 0;
    std::uint_fast64_t moves = 0;

    std::cin >> n;
    for (std::uint_fast32_t i = 0; i < n; ++i) {
        std::cin >> x;
        max_x = std::max(x, max_x);
        moves += max_x - x;
    }

    std::cout << moves << '\n';
}
