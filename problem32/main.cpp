#include <bits/stdc++.h>

#include <iostream>

void fun(std::vector<int> &digits, int idx, std::unordered_set<int> &us,
         std::unordered_set<int> &us_res) {
    if (idx >= digits.size()) {
        for (int i = 0; i < digits.size(); ++i) {
            for (int j = i + 1; j < digits.size(); ++j) {
                int a = 0;
                for (int k = 0; k < i; ++k) {
                    a = a * 10 + digits[k];
                }
                int b = 0;
                for (int k = i; k < j; ++k) {
                    b = b * 10 + digits[k];
                }
                int c = 0;
                for (int k = j; k < digits.size(); ++k) {
                    c = c * 10 + digits[k];
                }
                if (a == 0 || b == 0 || c == 0) {
                    continue;
                }
                // std::cout << "=> " << a << " x " << b << " = " << c
                //           << std::endl;
                if (a * b == c) {
                    std::cout << a << " x " << b << " = " << c << std::endl;
                    us_res.insert(c);
                }
            }
        }
    } else {
        for (int i = 1; i <= 9; ++i) {
            if (us.find(i) == us.end()) {
                digits[idx] = i;
                us.insert(i);
                fun(digits, idx + 1, us, us_res);
                us.erase(i);
            }
        }
    }
}

int solve() {
    std::vector<int> digits(9);
    std::unordered_set<int> us;
    std::unordered_set<int> us_res;
    fun(digits, 0, us, us_res);

    int res = 0;
    for (const auto &p : us_res) {
        res += p;
    }
    return res;
}

int main() {
    auto res = solve();

    std::cout << "Result: " << res << std::endl;

    return 0;
}