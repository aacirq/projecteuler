#include <bits/stdc++.h>

#include <iostream>

bool is_prime(long long n) {
  int sqrt_n = static_cast<int>(std::sqrt(n));
  for (int i = 2; i <= sqrt_n; ++i) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}

int number_of_consecutive_primes(int a, int b) {
  int n = 0;
  while (true && n < 1000000) {
    long long cur_num =
        static_cast<long long>(n) * n + a * static_cast<long long>(n) + b;
    if (cur_num > 0 && is_prime(cur_num)) {
      ++n;
    } else {
      break;
    }
  }
  return n;
}

int solve() {
  std::unordered_set<long long> prime_set;
  int max_num = 0;
  int res = -999 * (-999);
  for (int a = -999; a < 1000; ++a) {
    for (int b = -999; b < 1000; ++b) {
      auto cur_num = number_of_consecutive_primes(a, b);
      if (cur_num > max_num) {
        max_num = cur_num;
        res = a * b;
      }
    }
  }
  return res;
}

int main() {
  auto res = solve();
  std::cout << "Result: " << res << std::endl;

  return 0;
}
