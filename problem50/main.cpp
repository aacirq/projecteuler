#include <cmath>
#include <iostream>
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

size_t consecutive_primes_count(long long prime, const std::vector<long long>& all_primes)
{
    size_t result = 0;

    for (size_t i = 0; i < all_primes.size(); ++i) {
        if (all_primes[i] > prime) {
            break;
        }
        long long sum = 0;
        size_t idx = i;
        while (idx < all_primes.size() && sum < prime) {
            sum += all_primes[idx];
            ++idx;
        }
        if (sum == prime) {
            size_t count = idx - i;
            if (count > result) {
                result = count;
            }
        }
    }

    return result;
}

int main()
{
    std::vector<long long> all_primes;

    for (int i = 2; i < 1000000; ++i) {
        if (isPrime(i)) {
            all_primes.emplace_back(i);
        }
    }

    size_t max_count = 0;
    long long result = 0;

    for (size_t i = 0; i < all_primes.size(); ++i) {
        size_t count = consecutive_primes_count(all_primes[i], all_primes);
        if (count > max_count) {
            max_count = count;
            result = all_primes[i];
            std::cout << "Current result: " << result << ", count: " << max_count << std::endl;
        }
    }

    std::cout << "Result: " << result << std::endl;

    return 0;
}
