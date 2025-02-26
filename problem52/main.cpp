#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

bool isPermutedMultiple(long long num)
{
    std::string num_str = std::to_string(num);
    std::sort(num_str.begin(), num_str.end());
    auto base_num = std::stoll(num_str);
    for (long long x = 2; x <= 6; ++x) {
        std::string cur_num = std::to_string(x * num);
        std::sort(cur_num.begin(), cur_num.end());
        if (base_num != std::stoll(cur_num)) {
            return false;
        }
    }
    return true;
}

int main(int argc, const char* argv[])
{
    long long num = 1;
    while (true) {
        if (isPermutedMultiple(num)) {
            std::cout << "Result: " << num << std::endl;
            std::cout << "Multiple: " << std::endl;
            for (long long x = 2; x <= 6; ++x) {
                std::cout << "  " << x << " * " << num << " = " << x * num << std::endl;
            }
            return 0;
        }
        ++num;
    }

    return 0;
}
