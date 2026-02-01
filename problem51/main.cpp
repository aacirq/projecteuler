#include <iostream>
#include <unordered_set>
#include <vector>
#include <cmath>
#include <string>

bool isPrime(long long x)
{
    if (x < 2) {
        return false;
    }

    auto limit = static_cast<long long>(std::sqrt(x));
    for (long long i = 2; i <= limit; ++i) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}

size_t replaceCount(long long n)
{
    std::string n_str = std::to_string(n);
    size_t length = n_str.size();
    size_t max_count = 0;
    std::vector<size_t> index_for_max;
    for (int count = 1; count < length; ++count) {
        std::vector<size_t> index(count, 0);
        for (int i = 0; i < count; ++i) {
            index[i] = i;
        }
        while (true) {
            // same digits in index
            bool all_same = true;
            if (index.size() > 1) {
                for (size_t i = 1; i < index.size(); ++i) {
                    if (n_str[index[i]] != n_str[index[0]]) {
                        all_same = false;
                        break;
                    }
                }
            }

            if (all_same) {
                char digit = n_str[index[0]];
                size_t prime_count = 1;
                std::string temp_str = n_str;
                ++digit;
                for (; digit <= '9'; ++digit) {
                    for (unsigned long i : index) {
                        temp_str[i] = digit;
                    }
                    long long temp_n = std::stoll(temp_str);
                    if (isPrime(temp_n)) {
                        ++prime_count;
                    }
                }
                if (prime_count > max_count) {
                    max_count = prime_count;
                    index_for_max = index;
                }
            }

            // ++ index
            bool can_continue = true;
            index.back()++;
            int i = static_cast<int>(index.size()) - 1;
            while (i >= 0) {
                // index.size() - 1  ->  length
                // index.size() - 2  ->  length - 1
                // index.size() - 3  ->  length - 2
                if (index[i] >= length - (index.size() - 1 - i)) {
                    if (i == 0) {
                        can_continue = false;
                        break;
                    }
                    index[i - 1]++;
                    --i;
                }
                else {
                    break;
                }
            }
            if (!can_continue) {
                break;
            }
            for (int j = i + 1; j < static_cast<int>(index.size()); ++j) {
                index[j] = index[j - 1] + 1;
            }
        }
    }

    if (max_count > 5) {
        std::cout << "n: " << n << ", count: " << max_count << ", index: ";
        for (unsigned long i : index_for_max) {
            std::cout << i << " ";
        }
        std::cout << std::endl;
    }

    return max_count;
}

int main()
{
    long long n = 2;
    while (true) {
        if (isPrime(n)) {
            size_t replace_count = replaceCount(n);
            if (replace_count == 8) {
                std::cout << "Result: " << n << std::endl;
                break;
            }
        }
        ++n;
    }
    return 0;
}
