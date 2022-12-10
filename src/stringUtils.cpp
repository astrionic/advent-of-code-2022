#include "stringUtils.h"
#include <sstream>
#include <vector>

std::vector<std::string> splitString(const std::string& s, char delimiter) {
    std::stringstream stream(s);
    std::string segment;
    std::vector<std::string> segments;

    while(std::getline(stream, segment, delimiter)) {
        segments.push_back(segment);
    }

    return segments;
}

std::vector<std::string> splitString(const std::string& s, const std::string& delimiter) {
    const unsigned long delimiterLength = delimiter.length();
    std::string remaining = s;
    std::vector<std::string> segments {};

    while(remaining.length() > 0) {
        const unsigned long nextDelimiterPos = remaining.find(delimiter);

        if(nextDelimiterPos == std::string::npos) {
            segments.push_back(remaining);
            remaining = "";
        } else {
            segments.push_back(remaining.substr(0, nextDelimiterPos));
            remaining = remaining.substr(nextDelimiterPos + delimiterLength);
        }
    }

    return segments;
}
