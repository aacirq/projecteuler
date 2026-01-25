#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <vector>

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

int main()
{
    std::unordered_map<std::string, std::vector<long long>> permuted_primes;

    for (long long x = 1000; x <= 9999; ++x) {
        if (isPrime(x)) {
            std::string str = std::to_string(x);
            std::sort(str.begin(), str.end());
            permuted_primes[str].emplace_back(x);
        }
    }

    for (const auto& pair : permuted_primes) {
        const auto& primes = pair.second;
        if (primes.size() < 3) {
            continue;
        }

        for (size_t i = 0; i < primes.size(); ++i) {
            for (size_t j = i + 1; j < primes.size(); ++j) {
                long long diff = primes[j] - primes[i];
                long long third = primes[j] + diff;
                if (std::find(primes.begin(), primes.end(), third) != primes.end()) {
                    std::cout << "got: " << primes[i] << ", " << primes[j] << ", " << third << "; "
                              << primes[i] << primes[j] << third << std::endl;
                }
            }
        }
    }

    return 0;
}
