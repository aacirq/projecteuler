#include <bits/stdc++.h>

#include <iostream>

int solve(int maxa, int maxb) {
    std::unordered_map<int, std::unordered_set<int>> um;
    std::unordered_set<int> us;
    for (int a = 2; a <= maxa; ++a) {
        if (us.find(a) == us.end()) {
            int cura = a;
            int times = 1;
            while (cura <= maxa) {
                us.insert(cura);
                for (int b = 2; b <= maxb; ++b) {
                    um[a].insert(b * times);
                }
                cura *= a;
                ++times;
            }
        }
    }

    int res = 0;
    for (const auto &p : um) {
        res += p.second.size();
    }
    return res;
}

int main(int argc, char **argv) {
    if (argc < 3) {
        std::cout << "Usage: " << argv[0] << " a b" << std::endl;
        return -1;
    }

    auto res = solve(std::stoi(argv[1]), std::stoi(argv[2]));
    std::cout << "Result: " << res << std::endl;

    return 0;
}