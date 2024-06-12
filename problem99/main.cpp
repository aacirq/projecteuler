#include <cmath>
#include <fstream>
#include <iostream>

class Exponential {
    friend bool operator<(const Exponential &lhs, const Exponential &rhs);
    friend std::ostream &operator<<(std::ostream &ostm, const Exponential &v);
    friend std::istream &operator>>(std::istream &istm, Exponential &v);

   public:
    using base_type = long long;
    using exp_type = long long;

   private:
    base_type base;
    exp_type exponent;

   public:
    Exponential(const base_type &base_ = 0, const exp_type &exponent_ = 0)
        : base(base_), exponent(exponent_) {}
};

bool operator<(const Exponential &lhs, const Exponential &rhs) {
    /**
     * Result may be overflow if compute base ^ exponent directly.
     * So, based on below principle
     *    a^x < b^y
     * => log(a^x) < log(b^y)
     * => x * log(a) < y * log(b)
     * compute exponent * log(base) to avoid overflow.
     */
    return lhs.exponent * std::log(static_cast<double>(lhs.base)) <
           rhs.exponent * std::log(static_cast<double>(rhs.base));
}

std::ostream &operator<<(std::ostream &ostm, const Exponential &v) {
    ostm << v.base << "^" << v.exponent;
    return ostm;
}

std::istream &operator>>(std::istream &istm, Exponential &v) {
    char _;
    istm >> v.base;
    istm >> _;
    istm >> v.exponent;
    return istm;
}

Exponential max(const Exponential &lhs, const Exponential &rhs) {
    if (lhs < rhs) {
        return rhs;
    } else {
        return lhs;
    }
}

int main(int argc, char **argv) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <filename>" << std::endl;
        return EXIT_FAILURE;
    }

    std::ifstream ifs(argv[1]);

    if (!ifs.is_open()) {
        std::cerr << "Open file[" << argv[1] << "] failed" << std::endl;
        return EXIT_FAILURE;
    }

    Exponential cur_val;
    Exponential max_val;
    std::cout << "here" << std::endl;
    ifs >> cur_val;
    max_val = cur_val;
    int res = 1;
    int i = 1;
    while (ifs >> cur_val) {
        ++i;
        if (max_val < cur_val) {
            res = i;
            max_val = cur_val;
        }
    }

    std::cout << "Result: " << res << std::endl;
    std::cout << "max_val: " << max_val << std::endl;

    return EXIT_SUCCESS;
}
