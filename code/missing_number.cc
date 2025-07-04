#include <cstdint>
#include <iostream>

int main()
{
    uint_fast32_t n;
    std::cin >> n; // 2 <= n <= 2 * 10^5.

    uint_fast64_t s = n * (n + 1) / 2;
    for (uint_fast32_t i = 0; i < n - 1; ++i) {
        uint_fast32_t k; // 1 <= k <= n.
        std::cin >> k;
        s -= k;
    }
    std::cout << s << '\n';
}
