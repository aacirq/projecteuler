#include <iostream>

long long solve() {
  long long res = 0;

  int idx3{1};
  int idx5{1};

  int thresh = 1000;
  int cur = 0;

  while (true) {
    int cur3 = idx3 * 3;
    int cur5 = idx5 * 5;

    if (cur3 <= cur5) {
      cur = cur3;
    } else {
      cur = cur5;
    }

    if (cur >= thresh) {
      break;
    }
    res += cur;

    if (cur3 == cur) {
      ++idx3;
    }

    if (cur5 == cur) {
      ++idx5;
    }
  };

  return res;
}

int main() {
  std::cout << "result: " << solve() << std::endl;

  return 0;
}