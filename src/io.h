#pragma once

#include <fstream>
#include <iostream>
#include <optional>
#include <sstream>
#include <string>

std::optional<int> parseInt(const char* const c) {
    std::istringstream ss(c);
    int n;
    if(!(ss >> n)) {
        std::cerr << "Invalid number: " << c << '\n';
        return {};
    } else if(!ss.eof()) {
        std::cerr << "Trailing characters after number: " << '\n';
        return {};
    } else {
        return n;
    }
}

std::string readFile(const std::string& path) {
    std::ifstream stream(path);
    std::stringstream buffer;
    buffer << stream.rdbuf();
    return buffer.str();
}

std::string getInputForDay(int day) {
    std::string fileName = std::to_string(day) + ".txt";

    if(day < 10 && day >= 0) {
        fileName = "0" + fileName;
    }

    std::string path = "./resources/aoc-input/" + fileName;

    return readFile(path);
}
