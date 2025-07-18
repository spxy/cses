// https://cses.fi/problemset/task/1069

#include <algorithm>
#include <cstdint>
#include <iostream>
#include <string>

int main()
{
    std::string s; // 1 <= s.size() <= 1000000
    std::cin >> s;

    std::uint_fast32_t len = 1;
    std::uint_fast32_t max_len = 1;

    for (std::uint_fast32_t i = 1; i < s.size(); ++i) {
        if (s[i - 1] == s[i]) {
            ++len;
        } else {
            max_len = std::max(len, max_len);
            len = 1;
        }
    }

    max_len = std::max(len, max_len);
    std::cout << max_len << '\n';
}
