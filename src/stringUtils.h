#pragma once

#include <string>
#include <vector>

std::vector<std::string> splitString(const std::string& s, char separator);

std::vector<std::string> splitString(const std::string& s, const std::string& separator);
std::vector<std::string> splitString(const std::string& s, const std::string& separator, bool allowEmpty);

std::string joinStrings(const std::vector<std::string>& strings, const std::string& separator);
