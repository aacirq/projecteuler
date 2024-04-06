#include <bits/stdc++.h>

#include <iostream>

void put_spiral(std::vector<std::vector<int>> &spiral, int n) {
    static std::vector<int> row_increment{1, 0, -1, 0};
    static std::vector<int> col_increment{0, 1, 0, -1};

    int r = n / 2;
    int c = n / 2;
    int dir = 0;
    int len = 1;
    int number = 1;
    // std::cout << "spiral(" << r << ", " << c << ")=" << number << std::endl;
    spiral[r][c] = number;
    ++number;
    while (len < n) {
        for (int i = 0; i < len; ++i) {
            r += row_increment[dir];
            c += col_increment[dir];
            spiral[r][c] = number;
            // std::cout << "spiral(" << r << ", " << c << ")=" << number
            //           << std::endl;
            ++number;
        }
        dir = (dir + 1) % 4;
        for (int i = 0; i < len; ++i) {
            r += row_increment[dir];
            c += col_increment[dir];
            spiral[r][c] = number;
            // std::cout << "spiral(" << r << ", " << c << ")=" << number
            //           << std::endl;
            ++number;
        }
        dir = (dir + 1) % 4;
        ++len;
    }

    for (int i = 1; i < n; ++i) {
        r += row_increment[dir];
        c += col_increment[dir];
        spiral[r][c] = number;
        // std::cout << "spiral(" << r << ", " << c << ")=" << number <<
        // std::endl;
        ++number;
    }
}

int solve(int n) {
    std::vector<std::vector<int>> spiral;
    for (size_t i = 0; i < n; ++i) {
        spiral.push_back(std::vector<int>(n, 0));
    }

    put_spiral(spiral, n);

    int res = 0;
    for (size_t i = 0; i < n; ++i) {
        res += spiral[i][i];
    }
    for (size_t i = 0; i < n; ++i) {
        res += spiral[i][n - 1 - i];
    }
    res -= spiral[n / 2][n / 2];
    return res;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        std::cout << "Usage: " << argv[0] << " N" << std::endl;
        return -1;
    }
    std::cout << "Result: " << solve(std::stoi(argv[1])) << std::endl;
    return 0;
}
