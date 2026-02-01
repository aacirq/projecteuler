#pragma once

#include <cstdint>
#include <iostream>
#include <vector>
#include <algorithm>

class BigUInt
{
    friend std::ostream& operator<<(std::ostream& os, const BigUInt& rhs);
    friend bool operator<(const BigUInt& lhs, const BigUInt& rhs);
    friend bool operator>(const BigUInt& lhs, const BigUInt& rhs);
    friend bool operator==(const BigUInt& lhs, const BigUInt& rhs);

public:
    explicit BigUInt(uint64_t n)
    {
        while (n) {
            hex_digits.push_back(static_cast<char>(n % 10));
            n /= 10;
        }
    }

    BigUInt operator+(const BigUInt& rhs) const
    {
        BigUInt result {0};
        const size_t max_count = std::max(this->hex_digits.size(), rhs.hex_digits.size());
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
            result.hex_digits.push_back(static_cast<char>(cur_sum % 10));
            carry = cur_sum / 10;
        }
        return result;
    }

    BigUInt operator*(const BigUInt& rhs) const
    {
        BigUInt result {0};
        const size_t total_count = this->hex_digits.size() + rhs.hex_digits.size();
        result.hex_digits.reserve(total_count);
        int carry = 0;
        for (size_t i = 0; i < total_count; ++i) {
            int cur_sum = carry;
            for (size_t j = 0; j <= i; ++j) {
                if (j < this->hex_digits.size() && i - j < rhs.hex_digits.size()) {
                    cur_sum += this->hex_digits[j] * rhs.hex_digits[i - j];
                }
            }
            result.hex_digits.push_back(static_cast<char>(cur_sum % 10));
            carry = cur_sum / 10;
        }

        while (carry) {
            result.hex_digits.push_back(static_cast<char>(carry % 10));
            carry /= 10;
        }

        while (!result.hex_digits.empty() && result.hex_digits.back() == 0) {
            result.hex_digits.pop_back();
        }

        return result;
    }

private:
    std::vector<char> hex_digits;
};

inline std::ostream& operator<<(std::ostream& os, const BigUInt& rhs)
{
    std::vector<char> reversed_digits = rhs.hex_digits;
    std::reverse(reversed_digits.begin(), reversed_digits.end());
    for (const char digit : reversed_digits) {
        os << static_cast<int>(digit);
    }

    return os;
}

inline bool operator<(const BigUInt& lhs, const BigUInt& rhs)
{
    if (lhs.hex_digits.size() != rhs.hex_digits.size()) {
        return lhs.hex_digits.size() < rhs.hex_digits.size();
    }

    if (lhs.hex_digits.empty()) {
        return false;
    }

    for (size_t i = lhs.hex_digits.size() - 1; i > 0; --i) {
        if (lhs.hex_digits[i] != rhs.hex_digits[i]) {
            return lhs.hex_digits[i] < rhs.hex_digits[i];
        }
    }

    return false;
}

inline bool operator>(const BigUInt& lhs, const BigUInt& rhs)
{
    if (lhs.hex_digits.size() != rhs.hex_digits.size()) {
        return lhs.hex_digits.size() > rhs.hex_digits.size();
    }

    if (lhs.hex_digits.empty()) {
        return false;
    }

    for (size_t i = lhs.hex_digits.size() - 1; i > 0; --i) {
        if (lhs.hex_digits[i] != rhs.hex_digits[i]) {
            return lhs.hex_digits[i] > rhs.hex_digits[i];
        }
    }

    return false;
}

inline bool operator==(const BigUInt& lhs, const BigUInt& rhs)
{
    if (lhs.hex_digits.size() != rhs.hex_digits.size()) {
        return false;
    }

    for (size_t i = 0; i < lhs.hex_digits.size(); ++i) {
        if (lhs.hex_digits[i] != rhs.hex_digits[i]) {
            return false;
        }
    }

    return true;
}

inline bool operator!=(const BigUInt& lhs, const BigUInt& rhs)
{
    return !(lhs == rhs);
}
