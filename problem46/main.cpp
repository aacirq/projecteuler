#include <iostream>
#include <vector>
#include <cmath>

bool isPrime(long long x)
{
    if (x < 2) {
        return false;
    }

    long long limit = static_cast<long long>(std::sqrt(x));
    for (long long i = 2; i <= limit; ++i) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}

bool isTwiceSquare(long long x)
{
    if (x % 2 != 0) {
        return false;
    }

    double root = std::sqrt(x / 2.0);
    return static_cast<long long>(root) == root;
}

int main()
{
    std::vector<long long> primes;

    int n = 2;
    while (true) {
        if (n % 2 == 0) {
            ++n;
            continue;
        }
        if (isPrime(n)) {
            primes.emplace_back(n);
        }
        else {
            bool passed = false;
            for (const auto prime : primes) {
                if (isTwiceSquare(n - prime)) {
                    passed = true;
                    break;
                }
            }
            if (!passed) {
                std::cout << "result: " << n << std::endl;
                break;
            }
        }
        ++n;
    }

    return 0;
}