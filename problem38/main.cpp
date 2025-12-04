#include <iostream>
#include <string>
#include <algorithm>

std::pair<bool, long long> pandigitalOf(long long n)
{
    std::string str;
    int i = 1;
    for (i = 1; i <= 9; ++i) {
        str += std::to_string(n * i);
        if (str.size() >= 9) {
            break;
        }
    }

    if (i <= 1) {
        return {false, 0};
    }

    if (str.size() != 9) {
        return {false, 0};
    }

    std::string str_backup = str;
    std::sort(str.begin(), str.end());

    for (int i = 0; i < str.size(); ++i) {
        if (str[i] != '1' + i) {
            return {false, 0};
        }
    }

    return {true, std::stoll(str_backup)};
}

int main()
{
    long long max_pandigital = 123456789;
    for (long long n = 1; n <= 100000000LL; ++n) {
        if (n % 1000000 == 0) {
            std::cout << "iter. " << n << std::endl;
        }
        auto p = pandigitalOf(n);
        if (p.first) {
            std::cout << p.second << std::endl;
            max_pandigital = std::max(max_pandigital, p.second);
        }
    }

    std::cout << "Result: " << max_pandigital << std::endl;
    return 0;
}
