#include <iostream>
#include <vector>

bool isPrime(long long x)
{
    if (x < 2) {
        return false;
    }
    if (x == 2) {
        return true;
    }
    if (x % 2 == 0) {
        return false;
    }

    for (long long i = 3; i * i <= x; i += 2) {
        if (x % i == 0) {
            return false;
        }
    }

    return true;
}

bool isTruncatablePrime(long long x)
{
    long long mod_num = 1;
    long long x_backup = x;
    while (x) {
        if (!isPrime(x)) {
            return false;
        }
        mod_num *= 10;
        x /= 10;
    }

    mod_num /= 10;
    x = x_backup % mod_num;
    while (x) {
        if (!isPrime(x)) {
            return false;
        }
        mod_num /= 10;
        x = x % mod_num;
    }

    return true;
}

int main()
{
    long long sum = 0;
    long long x = 10;
    int num = 0;
    while (num < 11) {
        if (isTruncatablePrime(x)) {
            ++num;
            sum += x;
            std::cout << num << ": " << x << std::endl;
        }
        ++x;
    }

    std::cout << "Result: " << sum << std::endl;

    return 0;
}
