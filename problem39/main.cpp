#include <iostream>
#include <tuple>

int solutionCount(int p)
{
    int res = 0;
    for (int a = 1; a < p / 3; ++a) {
        for (int b = a; b < p - a - b; ++b) {
            int c = p - a - b;
            if (a * a + b * b == c * c) {
                ++res;
            }
        }
    }

    return res;
}

int main()
{
    int num_solution = 0;
    int result = 0;

    for (int p = 3; p <= 1000; ++p) {
        auto num = solutionCount(p);
        if (num > num_solution) {
            std::cout << "p(" << p << ") has " << num << " solutions" << std::endl;
            num_solution = num;
            result = p;
        }
    }

    std::cout << "Result: " << result << std::endl;

    return 0;
}
