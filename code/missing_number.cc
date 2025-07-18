// https://cses.fi/problemset/task/1083

#include <cstdint>
#include <iostream>

int main()
{
    std::uint_fast32_t n;
    std::cin >> n; // 2 <= n <= 2 * 10^5.

    std::uint_fast64_t s = n * (n + 1) / 2;
    for (std::uint_fast32_t i = 0; i < n - 1; ++i) {
        std::uint_fast32_t k; // 1 <= k <= n.
        std::cin >> k;
        s -= k;
    }
    std::cout << s << '\n';
}
