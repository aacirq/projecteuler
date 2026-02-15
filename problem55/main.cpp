#include "../util/BigUInt.hpp"

#include <iostream>

bool isPalindromic(const BigUInt& n)
{
    const auto data = n.data();
    auto data_reverse = data;
    std::reverse(data_reverse.begin(), data_reverse.end());
    return data == data_reverse;
}

BigUInt reverse(const BigUInt& n)
{
    auto data = n.data();
    std::reverse(data.begin(), data.end());
    return BigUInt(data);
}

bool isLychrel(const BigUInt& n)
{
    BigUInt num = n;
    for (size_t i = 0; i < 50; ++i) {
        auto num_reversed = reverse(num);
        num = num + num_reversed;
        if (isPalindromic(num)) {
            return false;
        }
    }

    return true;
}

int main()
{
    size_t count = 0;
    for (size_t i = 1; i < 10000; ++i) {
        if (isLychrel(BigUInt(i))) {
            std::cout << "count: " << count << "; lychrel: " << i << std::endl;
            ++count;
        }
    }

    std::cout << "Result: " << count << std::endl;

    return 0;
}
