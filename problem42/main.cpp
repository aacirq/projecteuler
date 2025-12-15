#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <optional>

std::vector<std::string> readWords(const std::string& filename)
{
    std::ifstream file(filename);
    std::vector<std::string> words;

    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return words;
    }

    std::string word;
    while (std::getline(file, word, ',')) {
        if (word.size() <= 2) {
            std::cerr << "Invalid word format: " << word << std::endl;
            continue;
        }
        words.push_back(word.substr(1, word.size() - 2));
    }

    return words;
}

size_t wordValue(const std::string& word)
{
    size_t value = 0;
    for (char ch : word) {
        value += (ch - 'A' + 1);
    }
    return value;
}

std::optional<size_t> solveTriangleNumber(size_t number)
{
    double delta = 1 + 8 * number;
    double sqrt_delta = std::sqrt(delta);
    if (sqrt_delta != static_cast<size_t>(sqrt_delta)) {
        return {};
    }

    double n = (-1 + sqrt_delta) / 2;
    if (n != static_cast<size_t>(n)) {
        return {};
    }

    return static_cast<size_t>(n);
}

int main(int argc, const char* argv[])
{
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <words_file>" << std::endl;
        return 1;
    }

    size_t num_triangle_words = 0;

    std::vector<std::string> words = readWords(argv[1]);
    for (const auto& word : words) {
        auto value = wordValue(word);
        auto n = solveTriangleNumber(value);
        if (n.has_value()) {
            std::cout << word << " | " << value << " | " << n.value() << " * " << n.value() + 1
                      << " * 0.5"
                      << " = " << (n.value() * (n.value() + 1) * 0.5) << std::endl;
            num_triangle_words++;
        }
    }

    std::cout << "Result: " << num_triangle_words << std::endl;

    return 0;
}
