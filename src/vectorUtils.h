#pragma once

#include <vector>

template<typename T1, typename T2> std::vector<T2> map(const std::vector<T1>& v, const std::function<T2(T1)>& f) {
    std::vector<T2> result;
    std::transform(v.begin(), v.end(), std::back_inserter(result), f);
    return result;
}
