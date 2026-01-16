#include <iostream>
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

bool isHexagonal(long long hn)
{
    double delta = 1 + 8 * hn;
    double delta_sqrt = std::sqrt(delta);
    if (static_cast<long long>(delta_sqrt) != delta_sqrt) {
        return false;
    }

    double n = (1 + delta_sqrt) / 4;
    if (static_cast<long long>(n) != n) {
        return false;
    }

    return true;
}

int main()
{
    long long n = 286;

    while (true) {
        long long tn = n * (n + 1) / 2;
        if (isPentagonal(tn) && isHexagonal(tn)) {
            std::cout << "result: " << tn << std::endl;
            break;
        }
        ++n;
    }

    return 0;
}