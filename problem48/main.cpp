#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>
#include <string>

class BigUInt
{
    friend std::ostream& operator<<(std::ostream& os, const BigUInt& rhs);

public:
    BigUInt(uint64_t n)
    {
        while (n) {
            hex_digits.push_back(n % 10);
            n /= 10;
        }
    }

    BigUInt operator+(const BigUInt& rhs)
    {
        BigUInt result = 0;
        size_t max_count = std::max(this->hex_digits.size(), rhs.hex_digits.size());
        result.hex_digits.reserve(max_count);
        int carry = 0;
        for (size_t i = 0; i < max_count; ++i) {
            int cur_sum = carry;
            if (i < this->hex_digits.size()) {
                cur_sum += this->hex_digits[i];
            }
            if (i < rhs.hex_digits.size()) {
                cur_sum += rhs.hex_digits[i];
            }
            result.hex_digits.push_back(cur_sum % 10);
            carry = cur_sum / 10;
        }
        return result;
    }

    BigUInt operator*(const BigUInt& rhs)
    {
        BigUInt result = 0;
        size_t total_count = this->hex_digits.size() + rhs.hex_digits.size();
        result.hex_digits.reserve(total_count);
        int carry = 0;
        for (size_t i = 0; i < total_count; ++i) {
            int cur_sum = carry;
            for (size_t j = 0; j <= i; ++j) {
                if (j < this->hex_digits.size() && (i - j) < rhs.hex_digits.size()) {
                    cur_sum += this->hex_digits[j] * rhs.hex_digits[i - j];
                }
            }
            result.hex_digits.push_back(cur_sum % 10);
            carry = cur_sum / 10;
        }

        while (carry) {
            result.hex_digits.push_back(carry % 10);
            carry /= 10;
        }

        while (result.hex_digits.size() > 0 && result.hex_digits.back() == 0) {
            result.hex_digits.pop_back();
        }

        return result;
    }

private:
    std::vector<char> hex_digits;
};

std::ostream& operator<<(std::ostream& os, const BigUInt& rhs)
{
    std::vector<char> reversed_digits = rhs.hex_digits;
    std::reverse(reversed_digits.begin(), reversed_digits.end());
    for (char digit : reversed_digits) {
        os << static_cast<int>(digit);
    }

    return os;
}

BigUInt pow_biguint(uint64_t x, uint64_t n)
{
    if (n == 0) {
        return 1;
    }
    if (n == 1) {
        return x;
    }

    uint64_t n_half = n / 2;
    BigUInt x2 = pow_biguint(x, n_half);

    if (n - n_half == n_half) {
        return x2 * x2;
    }
    else {
        return x2 * x2 * BigUInt(x);
    }
}

int main()
{
    uint64_t max_n = 1000;

    BigUInt result = 0;
    for (uint64_t i = 1; i <= max_n; ++i) {
        result = pow_biguint(i, i) + result;
    }

    std::cout << "Result: " << result << std::endl;

    return 0;
}