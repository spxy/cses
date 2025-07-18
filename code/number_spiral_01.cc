// https://cses.fi/problemset/task/1071/

// Simple solution based on edge numbers.

#include <cstdint>
#include <iostream>

using u32 = std::uint_fast32_t;
using u64 = std::uint_fast64_t;

template <typename T, typename U>
constexpr T to(U x)
{
    return static_cast<T>(x);
}

u64 f(u32 y, u32 x)
{
    u64 r;
    if (x <= y) { // On or below diagonal.
        if (y % 2 == 0) {
            r = to<u64>(y) * y - x + 1;
        } else {
            r = (to<u64>(y) - 1) * (y - 1) + x;
        }
    } else { // Below diagonal.
        if (x % 2 == 1) {
            r = to<u64>(x) * x - y + 1;
        } else {
            r = (to<u64>(x) - 1) * (x - 1) + y;
        }
    }
    return r;
}

int main()
{
    u32 t;    // 1 <= t <= 10^5.
    u32 y, x; // 1 <= y, x <= 10^9.

    std::cin >> t;
    for (u32 i = 0; i < t; ++i) {
        std::cin >> y >> x;
        std::cout << f(y, x) << '\n';
    }
}
