#include "day01.h"
#include "../../stringUtils.h"
#include "../../vectorUtils.h"
#include <numeric>

std::string day01p1(const std::string& input) {
    const std::vector<std::string> elves = splitString(input, "\n\n");

    const std::vector<int> caloriesSums = map<std::string, int>(elves, [](const std::string& elfItems) {
        std::vector<std::string> caloriesString = splitString(elfItems, '\n');
        std::vector<int> calories =
            map<std::string, int>(caloriesString, [](const std::string& s) { return std::stoi(s); });
        int caloriesSum = std::reduce(calories.begin(), calories.end());
        return caloriesSum;
    });

    int max = *std::max_element(caloriesSums.begin(), caloriesSums.end());
    return std::to_string(max);
}
