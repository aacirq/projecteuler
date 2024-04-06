#include <bits/stdc++.h>

#include <iostream>

bool check_abundant(int num) {
    int sum = 0;
    for (int i = 1; i < num; ++i) {
        if (num % i == 0) {
            sum += i;
        }
    }
    return sum > num;
}

bool check_sum_of_tow_abundant_numbers(int i,
                                       const std::vector<int> &abundant_vec) {
    size_t left = 0;
    size_t right = abundant_vec.size() - 1;
    while (left < right) {
        int sum = abundant_vec[left] + abundant_vec[right];
        if (sum == i) {
            return true;
        } else if (sum > i) {
            --right;
        } else {
            ++left;
        }
    }
    if (left < abundant_vec.size()) {
        if (2 * abundant_vec[left] == i) {
            return true;
        }
    }
    if (right >= 0) {
        if (2 * abundant_vec[right] == i) {
            return true;
        }
    }
    return false;
}

long long solve() {
    std::vector<int> abundant_nums;
    for (int i = 1; i < 28123; ++i) {
        if (check_abundant(i)) {
            abundant_nums.push_back(i);
        }
    }

    // debug
    //   for (int i = 0; i < abundant_nums.size(); ++i) {
    //     std::cout << abundant_nums[i] << " ";
    //   }
    //   std::cout << std::endl;

    long long res = 0;
    for (int i = 1; i <= 28123; ++i) {
        if (!check_sum_of_tow_abundant_numbers(i, abundant_nums)) {
            //   std::cout << "check: " << i << std::endl;
            res += i;
        }
    }
    return res;
}

int main(int argc, char **argv) {
    std::cout << "Result: " << solve() << std::endl;
    return 0;
}
