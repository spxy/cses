// https://cses.fi/problemset/task/1071/

// Simple solution based on diagonal numbers.

#include <cstdint>
#include <iostream>

using i32 = std::int_fast32_t;
using u32 = std::uint_fast32_t;
using u64 = std::uint_fast64_t;

template <typename T, typename U>
constexpr T to(U x)
{
    return static_cast<T>(x);
}

u64 f(u32 y, u32 x)
{
    u64 diag;
    i32 sign;
    u32 dist;

    if (x <= y) { // On or below diagonal.
        diag = to<u64>(y) * (y - 1) + 1;
        sign = (y % 2 == 0) ? 1 : -1;
        dist = y - x;
    } else { // Above diagonal.
        diag = to<u64>(x) * (x - 1) + 1;
        sign = (x % 2 == 0) ? -1 : 1;
        dist = x - y;
    }

    return diag + to<u64>(sign * to<i32>(dist));
}

int main()
{
    int t;    // 1 <= t <= 10^5.
    int y, x; // 1 <= y, x <= 10^9.

    std::cin >> t;
    for (int i = 0; i < t; ++i) {
        std::cin >> y >> x;
        std::cout << f(y, x) << '\n';
    }
}
