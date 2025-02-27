#include <iostream>
#include <vector>
#include <algorithm>

std::vector<long long> fac;

bool isCurious(long long x)
{
    long long backup = x;
    long long sum = 0;
    while (x) {
        sum += fac[x % 10];
        x /= 10;
    }

    return backup == sum;
}

int main()
{
    for (long long i = 0; i < 10; ++i) {
        long long f = 1;
        for (long long j = 1; j <= i; ++j) {
            f *= j;
        }
        fac.push_back(f);
    }

    constexpr long long min_value = 3;
    constexpr long long max_value = 2540160;

    long long result = 0;
    for (long long x = min_value; x <= max_value; ++x) {
        if (isCurious(x)) {
            std::cout << x << " ";
            result += x;
        }
    }
    std::cout << std::endl;

    std::cout << "Result: " << result << std::endl;

    return 0;
}
