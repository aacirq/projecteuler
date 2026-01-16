#include <iostream>
#include <limits>
#include <vector>
#include <cmath>

bool isPentagonal(long long pn)
{
    double delta = 1 + 24 * pn;
    double delta_sqrt = std::sqrt(delta);
    if (static_cast<long long>(delta_sqrt) != delta_sqrt) {
        return false;
    }

    double n = (1 + delta_sqrt) / 6;
    if (static_cast<long long>(n) != n) {
        return false;
    }

    return true;
}

int main()
{
    std::vector<long long> vec;

    long long result = std::numeric_limits<long long>::max();
    long long n = 1;

    while (true) {
        if (n % 10000 == 0) {
            std::cout << "idx: " << n << " " << vec[vec.size() - 1] - vec[vec.size() - 2]
                      << std::endl;
        }
        long long pn = n * (3 * n - 1) / 2;
        ++n;
        if (!vec.empty()) {
            if (result <= pn - vec.back()) {
                break;
            }
        }
        for (int64_t i = vec.size() - 1; i >= 0; --i) {
            long long pk = vec[i];
            long long psum = pk + pn;
            long long pdiff = std::abs(pk - pn);

            if (pdiff >= result) {
                break;
            }

            if (isPentagonal(psum) && isPentagonal(pdiff)) {
                std::cout << "Found pentagonal pair: Pn = " << pn << ", Pk = " << pk
                          << ", current result: " << result << std::endl;
                result = std::min(result, pdiff);
            }
        }
        vec.emplace_back(pn);
    }

    std::cout << "Result: " << result << std::endl;

    return 0;
}