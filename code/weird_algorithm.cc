// https://cses.fi/problemset/task/1068

#include <cstdint>
#include <iostream>

int main()
{
    std::uint_fast64_t n; // 1 <= n <= 10^6.  But intermediates >= UINT32_MAX.
    std::cin >> n;
    while (n != 1) {
        std::cout << n << ' ';
        n = (n % 2 == 0) ? (n / 2) : (3 * n + 1);
    }
    std::cout << n << '\n';
}
