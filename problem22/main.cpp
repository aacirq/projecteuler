#include <bits/stdc++.h>

#include <iostream>

long long name_value(const std::string &name) {
  long long res = 0;
  for (const auto &c : name) {
    res += c - 'A' + 1;
  }
  return res;
}

long long solve(const std::string &filename) {
  std::ifstream ifstm(filename);
  std::string buf;
  ifstm >> buf;

  std::vector<std::string> svec;
  int idx = 0;
  while (idx < buf.size()) {
    if (buf[idx] == ',') {
      ++idx;
    }
    ++idx;
    int jdx = idx;
    while (buf[jdx] != '\"') {
      ++jdx;
    }
    svec.emplace_back(buf.substr(idx, jdx - idx));
    idx = jdx + 1;
  }

  long long res = 0;
  std::sort(svec.begin(), svec.end());

  for (size_t i = 0; i < svec.size(); ++i) {
    res += (i + 1) * name_value(svec[i]);
  }

  return res;
}

int main(int argc, char **argv) {
  if (argc < 2) {
    std::cerr << "usage: " << argv[0] << " filename" << std::endl;
    return -1;
  }

  auto res = solve(argv[1]);
  std::cout << "Result: " << res << std::endl;

  return 0;
}
