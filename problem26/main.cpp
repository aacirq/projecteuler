#include <bits/stdc++.h>

#include <iostream>

int recurring_cycle_digit(int n) {
    int num = 1;
    std::vector<std::pair<int, int>> frac_res;
    while (true && frac_res.size() < 1000000) {
        int multiple = num * 10 / n;
        int remainder = num * 10 % n;
        // std::cout << "multiple: " << multiple << ", remainder: " << remainder
        //           << std::endl;
        if (remainder == 0) {
            break;
        }
        for (size_t i = 0; i < frac_res.size(); ++i) {
            if (frac_res[i].first == multiple &&
                frac_res[i].second == remainder) {
                return frac_res.size() - i;
            }
        }
        frac_res.push_back({multiple, remainder});
        num = remainder;
    }
    return 0;
}

int solve() {
    int res_d = 2;
    int max_digit = 0;
    for (int n = 2; n < 1000; ++n) {
        int cur_digit = recurring_cycle_digit(n);
        if (cur_digit > max_digit) {
            max_digit = cur_digit;
            res_d = n;
        }
    }
    return res_d;
}

int main() {
    auto res = solve();
    std::cout << "Result: " << res << std::endl;
    std::cout << "recurring cycle digit: " << recurring_cycle_digit(res)
              << std::endl;
    return 0;
}
