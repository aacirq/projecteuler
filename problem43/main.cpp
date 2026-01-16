#include <iostream>
#include <string>
#include <algorithm>

int main()
{
    std::string digits = "0123456789";
    long long total_sum = 0;

    do {
        if (digits[0] == '0') {
            continue;
        }

        if (std::stoi(digits.substr(1, 3)) % 2 != 0) {
            continue;
        }
        if (std::stoi(digits.substr(2, 3)) % 3 != 0) {
            continue;
        }
        if (std::stoi(digits.substr(3, 3)) % 5 != 0) {
            continue;
        }
        if (std::stoi(digits.substr(4, 3)) % 7 != 0) {
            continue;
        }
        if (std::stoi(digits.substr(5, 3)) % 11 != 0) {
            continue;
        }
        if (std::stoi(digits.substr(6, 3)) % 13 != 0) {
            continue;
        }
        if (std::stoi(digits.substr(7, 3)) % 17 != 0) {
            continue;
        }

        std::cout << "valid numbers: " << digits << std::endl;

        total_sum += std::stoll(digits);
    } while (std::next_permutation(digits.begin(), digits.end()));

    std::cout << "result: " << total_sum << std::endl;

    return 0;
}