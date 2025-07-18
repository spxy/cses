// https://cses.fi/problemset/task/1071/

// Compact solution based on diagonal numbers.

#include <algorithm>
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
    const u32 k = std::max(x, y);
    const u64 diag = 1 + to<u64>(k) * (k - 1);
    const i32 sign = (k % 2 == 0 ? 1 : -1);
    const i32 dist = to<i32>(y) - to<i32>(x);
    return diag + to<u64>(sign * dist);
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
