#include <bits/stdc++.h>

#include <iostream>

int gcd(int a, int b) {
    if (a % b == 0) {
        return b;
    }
    return gcd(b, a % b);
}

class Fraction {
    friend std::ostream &operator<<(std::ostream &ostm, const Fraction &val);

   public:
    Fraction(int num_, int den_) : num(num_), den(den_) {}

    void simplify() {
        int v = 0;
        if (num >= den) {
            v = gcd(num, den);
        } else {
            v = gcd(den, num);
        }
        assert(num % v == 0);
        assert(den % v == 0);
        num = num / v;
        den = den / v;
    }

    bool operator==(Fraction rhs) {
        Fraction lhs{*this};
        lhs.simplify();
        rhs.simplify();
        if (lhs.num == rhs.num && lhs.den == rhs.den) {
            return true;
        }
        return false;
    }

   private:
    int num;
    int den;
};

std::ostream &operator<<(std::ostream &ostm, const Fraction &val) {
    ostm << val.num << "/" << val.den;
    return ostm;
}

bool check_curious_fraction(int num, int den) {
    std::string num_str = std::to_string(num);
    std::string den_str = std::to_string(den);
    assert(num_str.size() == 2);
    assert(den_str.size() == 2);

    Fraction origin_frac(num, den);

    if (num_str[0] == den_str[0]) {
        int new_num = static_cast<int>(num_str[1] - '0');
        int new_den = static_cast<int>(den_str[1] - '0');
        if (new_num != 0 && new_den != 0 &&
            Fraction(new_num, new_den) == origin_frac) {
            return true;
        }
    }

    if (num_str[0] == den_str[1]) {
        int new_num = static_cast<int>(num_str[1] - '0');
        int new_den = static_cast<int>(den_str[0] - '0');
        if (new_num != 0 && new_den != 0 &&
            Fraction(new_num, new_den) == origin_frac) {
            return true;
        }
    }

    if (num_str[1] == den_str[0]) {
        int new_num = static_cast<int>(num_str[0] - '0');
        int new_den = static_cast<int>(den_str[1] - '0');
        if (new_num != 0 && new_den != 0 &&
            Fraction(new_num, new_den) == origin_frac) {
            return true;
        }
    }

    if (num_str[1] == den_str[1]) {
        int new_num = static_cast<int>(num_str[0] - '0');
        int new_den = static_cast<int>(den_str[0] - '0');
        if (new_num != 0 && new_den != 0 &&
            Fraction(new_num, new_den) == origin_frac) {
            return true;
        }
    }

    return false;
}

bool trival(int num, int den) {
    if (num % 10 == 0 && den % 10 == 0) {
        return true;
    }
    return false;
}

void solve() {
    std::vector<std::pair<int, int>> res_vec;
    for (int den = 99; den >= 10; --den) {
        for (int num = den - 1; num >= 10; --num) {
            if (!trival(num, den)) {
                if (check_curious_fraction(num, den)) {
                    res_vec.push_back({num, den});
                }
            }
        }
    }

    for (const auto &p : res_vec) {
        std::cout << "curious fraction:" << p.first << " " << p.second
                  << std::endl;
    }

    long long num_prod = 1;
    long long den_prod = 1;
    for (const auto &p : res_vec) {
        num_prod *= p.first;
        den_prod *= p.second;
    }

    Fraction res_frac(num_prod, den_prod);
    res_frac.simplify();
    std::cout << res_frac << std::endl;
}

int main() {
    solve();
    return 0;
}
