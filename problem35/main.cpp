#include <iostream>
#include <vector>

bool isPrime(int n)
{
    if (n < 2) {
        return false;
    }
    if (n == 2) {
        return true;
    }
    if (n % 2 == 0) {
        return false;
    }

    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) {
            return false;
        }
    }

    return true;
}

bool isCirclePrime(int n)
{
    if (!isPrime(n)) {
        return false;
    }

    int x = n;
    int base_num = 1;
    while (x) {
        x /= 10;
        base_num *= 10;
    }
    base_num /= 10;

    x = n / 10 + (n % 10) * base_num;
    while (x != n) {
        if (!isPrime(x)) {
            return false;
        }
        x = x / 10 + (x % 10) * base_num;
    }

    return true;
}

int main()
{
    constexpr int max_num = 1000000;

    int num = 0;
    for (int i = 1; i < max_num; ++i) {
        if (isCirclePrime(i)) {
            std::cout << i << std::endl;
            ++num;
        }
    }

    std::cout << "Result: " << num << std::endl;

    return 0;
}
