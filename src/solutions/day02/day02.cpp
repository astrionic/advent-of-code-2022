#include "day02.h"
#include "../../stringUtils.h"
#include "../../vectorUtils.h"
#include <numeric>
#include <tuple>
#include <vector>

namespace day02 {

std::vector<std::tuple<int, int>> parseInput(const std::string& input) {
    const auto lines = splitString(input, '\n');

    auto tuples = map<std::string, std::tuple<int, int>>(lines, [](std::string s) {
        const auto opp = (int) (s[0] - 'A') + 1; // A := 1 (rock); B := 2 (paper); C := 3 (scissors)
        const auto me = (int) (s[2] - 'X') + 1;  // X := 1 (rock); Y := 2 (paper); Z := 3 (scissors)

        return std::make_tuple(opp, me);
    });

    return tuples;
}

std::string part1(const std::string& input) {
    const auto rounds = parseInput(input);

    const auto scores = map<std::tuple<int, int>, int>(rounds, [](const std::tuple<int, int>& moves) {
        const int opp = std::get<0>(moves);
        const int me = std::get<1>(moves);
        const int score = ((me - opp) + 1 + 3) % 3 * 3 + me;
        return score;
    });

    const int totalScore = std::reduce(scores.begin(), scores.end());
    return std::to_string(totalScore);
}

std::string part2(const std::string& input) {
    const auto rounds = parseInput(input);

    const auto scores = map<std::tuple<int, int>, int>(rounds, [](const std::tuple<int, int>& moves) {
        const int opp = std::get<0>(moves);
        const int outcome = std::get<1>(moves); // 1 := lose; 2 := draw; 3 := win
        const int me = (opp + outcome) % 3 + 1;
        const int score = (outcome - 1) * 3 + me;
        return score;
    });

    const int totalScore = std::reduce(scores.begin(), scores.end());
    return std::to_string(totalScore);
}

} // namespace day02
