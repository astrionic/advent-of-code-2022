#include "day01.h"
#include "../../stringUtils.h"
#include "../../vectorUtils.h"
#include <numeric>

namespace day01 {

std::vector<int> parseInput(const std::string& input) {
    const std::vector<std::string> elves = splitString(input, "\n\n");

    std::vector<int> caloriesSums = map<std::string, int>(elves, [](const std::string& elfItems) {
        std::vector<std::string> caloriesString = splitString(elfItems, '\n');
        std::vector<int> calories =
            map<std::string, int>(caloriesString, [](const std::string& s) { return std::stoi(s); });
        int caloriesSum = std::reduce(calories.begin(), calories.end());
        return caloriesSum;
    });

    return caloriesSums;
}

std::string part1(const std::string& input) {
    const auto caloriesSums = parseInput(input);
    int max = *std::max_element(caloriesSums.begin(), caloriesSums.end());
    return std::to_string(max);
}

std::string part2(const std::string& input) {
    std::vector<int> sums = parseInput(input);
    std::sort(sums.begin(), sums.end());
    return std::to_string(std::reduce(sums.end() - 3, sums.end()));
}

} // namespace day01
