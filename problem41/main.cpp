#include <iostream>
#include <vector>
#include <algorithm>

bool isPrime(int n)
{
    int t = std::sqrt(static_cast<float>(n));
    for (int i = 2; i <= t; ++i) {
        if (n % i == 0) {
            return false;
        }
    }

    return true;
}

int main()
{
    int max_pandigital = 0;

    for (int len = 2; len <= 9; ++len) {
        std::vector<int> digits;
        for (int n = 1; n <= len; ++n) {
            digits.push_back(n);
        }

        std::vector<int> multiple(digits.size());
        multiple.back() = 1;
        if (multiple.size() > 1) {
            for (int i = multiple.size() - 2; i >= 0; --i) {
                multiple[i] = multiple[i + 1] * 10;
            }
        }

        do {
            int cur_value = 0;
            for (int i = 0; i < digits.size(); ++i) {
                cur_value += multiple[i] * digits[i];
            }
            if (isPrime(cur_value)) {
                std::cout << "pandigital: " << cur_value << std::endl;
                max_pandigital = std::max(cur_value, max_pandigital);
            }
        } while (std::next_permutation(digits.begin(), digits.end()));
    }

    std::cout << "Result: " << max_pandigital << std::endl;

    return 0;
}
