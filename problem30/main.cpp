#include <bits/stdc++.h>

#include <iostream>

int sum_of_power_of_digits(int n, const std::vector<int> &base) {
    int res = 0;
    while (n) {
        res += base[n % 10];
        n /= 10;
    }
    return res;
}

int solve(int p, int max_n) {
    std::vector<int> base(10);
    for (int n = 0; n < 10; ++n) {
        base[n] = std::pow(n, p);
    }

    int res = 0;
    for (int n = 2; n <= max_n; ++n) {
        auto s = sum_of_power_of_digits(n, base);
        if (s == n) {
            res += n;
        }
    }
    return res;
}

int main(int argc, char **argv) {
    if (argc < 3) {
        std::cout << "Usage: " << argv[0] << " p max_n" << std::endl;
        return -1;
    }

    auto res = solve(std::stoi(argv[1]), std::stoi(argv[2]));

    std::cout << "Result: " << res << std::endl;

    return 0;
}