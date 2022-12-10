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

std::vector<std::string> splitString(const std::string& s, const std::string& delimiter) {
    std::string remaining = s;
    std::vector<std::string> segments {};

    while(remaining.length() > 0) {
        const unsigned long nextDelimiterPos = remaining.find(delimiter);

        if(nextDelimiterPos == std::string::npos) {
            segments.push_back(remaining);
            remaining = "";
        } else {
            segments.push_back(remaining.substr(0, nextDelimiterPos));
            remaining = remaining.substr(nextDelimiterPos + delimiter.length());
        }
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
