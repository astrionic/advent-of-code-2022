#include "stringUtils.h"
#include <sstream>
#include <vector>

std::vector<std::string> splitString(const std::string& s, char separator) {
    std::stringstream stream(s);
    std::string segment;
    std::vector<std::string> segments;

    while(std::getline(stream, segment, separator)) {
        segments.push_back(segment);
    }

    return segments;
}

std::vector<std::string> splitString(const std::string& s, const std::string& separator) {
    return splitString(s, separator, false);
}

std::vector<std::string> splitString(const std::string& s, const std::string& separator, bool allowEmpty) {
    std::string remaining = s;
    std::vector<std::string> segments {};

    unsigned long nextSeparatorPos = remaining.find(separator);

    while(nextSeparatorPos != std::string::npos) {
        const auto segment = remaining.substr(0, nextSeparatorPos);

        if(!segment.empty() || allowEmpty) {
            segments.push_back(segment);
        }

        remaining = remaining.substr(nextSeparatorPos + separator.length());
        nextSeparatorPos = remaining.find(separator);
    }

    if(!remaining.empty() || allowEmpty) {
        segments.push_back(remaining);
    }

    return segments;
}

std::string joinStrings(const std::vector<std::string>& strings, const std::string& separator) {
    std::string joined;

    for(size_t i = 0; i < strings.size(); i++) {
        joined += strings[i];

        if(i != strings.size() - 1) {
            joined += separator;
        }
    }

    return joined;
}
