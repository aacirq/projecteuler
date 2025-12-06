#include <iostream>
#include <vector>
#include <string>

int main()
{
    std::vector<int> indexs = {1, 10, 100, 1000, 10000, 100000, 1000000};

    std::vector<int> value(indexs.size(), 0);

    int i = 0;
    int count = 0;
    int n = 1;
    while (i < indexs.size()) {
        auto str = std::to_string(n);
        auto cur_len = str.size();
        if (cur_len + count >= indexs[i]) {
            value[i] = static_cast<int>(str[indexs[i] - count - 1] - '0');
            ++i;
        }
        count += cur_len;
        ++n;
    }

    for (int id = 0; id < indexs.size(); ++id) {
        std::cout << "d_" << indexs[id] << " = " << value[id] << std::endl;
    }

    long long product = 1;
    for (const auto& v : value) {
        product *= v;
    }

    std::cout << "Result: " << product << std::endl;

    return 0;
}
