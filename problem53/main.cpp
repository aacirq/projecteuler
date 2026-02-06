#include <iostream>

#include "../util/BigUInt.hpp"

BigUInt fac(const uint64_t n)
{
    if (n == 0 || n == 1) {
        return BigUInt {1};
    }

    return BigUInt {n} * fac(n - 1);
}

bool combBigThanMillion(const uint64_t n, const uint64_t r)
{
    const BigUInt n_fac = fac(n);
    const BigUInt r_fac = fac(r);
    const BigUInt n_r_fac = fac(n - r);

    return n_fac > BigUInt {1000000} * r_fac * n_r_fac;
}

int main()
{
    size_t result = 0;

    for (uint64_t n = 1; n <= 100; ++n) {
        BigUInt n_fac = fac(n);
        for (uint64_t r = 1; r <= n; ++r) {
            if (combBigThanMillion(n, r)) {
                std::cout << "C(" << n << "," << r << ")" << std::endl;;
                ++result;
            }
        }
    }

    std::cout << "Result: " << result << std::endl;

    return 0;
}
