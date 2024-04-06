#include <bits/stdc++.h>

#include <iostream>

int fun(const std::vector<int> &coins_in_pence, int idx, int cursum) {
    if (idx >= coins_in_pence.size()) {
        if (cursum == 200) {
            return 1;
        } else {
            return 0;
        }
    } else {
        if (cursum > 200) {
            return 0;
        }
    }
    int res = 0;
    int max_count_of_this = (200 - cursum) / coins_in_pence[idx];
    for (int i = 0; i <= max_count_of_this; ++i) {
        res += fun(coins_in_pence, idx + 1, cursum + i * coins_in_pence[idx]);
    }
    return res;
}

int solve() {
    std::vector<int> coins_in_pence{200, 100, 50, 20, 10, 5, 2, 1};
    std::vector<int> count;
    int res = fun(coins_in_pence, 0, 0);
    return res;
}

int main() {
    auto res = solve();

    std::cout << "Result: " << res << std::endl;

    return 0;
}