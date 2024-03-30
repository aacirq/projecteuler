#include <bits/stdc++.h>

#include <iostream>

using NType = int;
using SumType = long long;

NType sum_of_divisor(NType n) {
  NType res = 0;
  for (NType i = 1; i < n; ++i) {
    if (n % i == 0) {
      res += i;
    }
  }
  return res;
}

SumType solve(NType n) {
  std::vector<NType> sum_vec(n + 1);

  for (NType i = 1; i < n; ++i) {
    auto cur_sum = sum_of_divisor(i);
    sum_vec[i] = cur_sum;
    std::cout << cur_sum << " ";
  }
  std::cout << std::endl;

  SumType res = 0;
  for (NType a = 1; a < n; ++a) {
    NType b = sum_vec[a];
    if (a != b && b < n && a == sum_vec[b]) {
      std::cout << "amicable: " << a << std::endl;
      res += a;
    }
  }
  return res;
}

int main(int argc, char **argv) {
  if (argc < 2) {
    std::cerr << "usage: " << argv[0] << " N" << std::endl;
    return -1;
  }
  int n = std::stoi(argv[1]);

  auto res = solve(n);
  std::cout << "Result: " << res << std::endl;

  return 0;
}
