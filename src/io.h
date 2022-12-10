#pragma once

#include <optional>

std::optional<int> parseInt(const char* c);

std::string readFile(const std::string& path);

std::string getInputForDay(int day);
