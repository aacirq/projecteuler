#include <iostream>
#include <vector>
#include <unordered_set>
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

std::vector<long long> primeFactors(long long x, const std::vector<long long>& primes)
{
    std::vector<long long> result;

    for (const auto& prime : primes) {
        if (prime * 2 > x) {
            break;
        }

        if (x % prime == 0) {
            result.emplace_back(prime);
        }
    }

    return result;
}

int main()
{
    std::vector<std::vector<long long>> prime_table;
    std::vector<long long> primes;
    int n = 1;
    while (true) {
        prime_table.emplace_back(primeFactors(n, primes));
        if (n >= 4) {
            if (prime_table[n - 1].size() >= 4 && prime_table[n - 2].size() >= 4
                && prime_table[n - 3].size() >= 4 && prime_table[n - 4].size() >= 4) {
                std::cout << "result: " << n - 3 << std::endl;
                std::cout << "prime factors of " << n - 3 << ": ";
                for (const auto& factor : prime_table[n - 4]) {
                    std::cout << factor << " ";
                }
                std::cout << std::endl;
                std::cout << "prime factors of " << n - 2 << ": ";
                for (const auto& factor : prime_table[n - 3]) {
                    std::cout << factor << " ";
                }
                std::cout << std::endl;
                std::cout << "prime factors of " << n - 1 << ": ";
                for (const auto& factor : prime_table[n - 2]) {
                    std::cout << factor << " ";
                }
                std::cout << std::endl;
                std::cout << "prime factors of " << n - 0 << ": ";
                for (const auto& factor : prime_table[n - 1]) {
                    std::cout << factor << " ";
                }
                std::cout << std::endl;
                break;
            }
        }

        ++n;
        if (isPrime(n)) {
            primes.emplace_back(n);
        }
    }
    return 0;
}