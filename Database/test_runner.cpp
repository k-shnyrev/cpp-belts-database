#include "test_runner.h"

void Assert(bool b, const std::string& hint) {
    AssertEqual(b, true, hint);
}

template<class T, class U>
bool operator==(const std::vector<T>& left, const std::vector<U>& right) {
    if (left.size() != right.size()) {
        return false;
    }
    for (int i = 0; i < left.size(); ++i) {
        if (left[i] != right[i]) {
            return false;
        }
    }
    return true;
}

template<class T, class U>
bool operator!=(const std::vector<T>& left, const std::vector<U>& right) {
    return !(left == right);
}
