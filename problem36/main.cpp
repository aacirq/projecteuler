#include <iostream>
#include <vector>
#include <string>

std::vector<int> digitsBase(int x, int base)
{
    std::vector<int> digits;
    while (x) {
        digits.push_back(x % base);
        x /= base;
    }

    return digits;
}

bool palindromVector(const std::vector<int>& digits)
{
    for (size_t i = 0; i * 2 < digits.size(); ++i) {
        if (digits[i] != digits[digits.size() - i - 1]) {
            return false;
        }
    }

    return true;
}

bool isPalindrome(int n)
{
    return palindromVector(digitsBase(n, 10)) && palindromVector(digitsBase(n, 2));
}

int main()
{
    long long sum = 0;
    for (int x = 1; x < 1000000; ++x) {
        if (isPalindrome(x)) {
            std::cout << x << std::endl;
            sum += x;
        }
    }

    std::cout << "Result: " << sum << std::endl;

    return 0;
}
