#include "io.h"
#include "solutions/day01/day01.h"
#include <iostream>
#include <vector>

typedef std::function<std::string(std::string)> solverFunction;

int main(int argc, char* argv[]) {
    const std::vector<std::vector<solverFunction>> days {{day01p1, day01p2}};

    int day = static_cast<int>(days.size());
    std::vector<solverFunction> daySolvers = days.back();
    solverFunction partSolver = daySolvers.back();

    if(argc >= 3) {
        std::optional<int> dayArg = parseInt(argv[1]);
        std::optional<int> partArg = parseInt(argv[2]);

        if(dayArg.has_value() && partArg.has_value()) {
            day = dayArg.value();
            daySolvers = days[day - 1];
            partSolver = daySolvers[partArg.value() - 1];
        } else {
            throw std::invalid_argument("Specified daySolvers or partSolver doesn't exist.");
        }
    }

    const std::string input = getInputForDay(day);
    std::cout << partSolver(input) << std::endl;
}
