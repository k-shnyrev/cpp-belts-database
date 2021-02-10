#include "test_runner.h"

template <class T>
std::ostream& operator<<(std::ostream& os, const std::set<T>& s) {
    os << "{";
    bool first = true;
    for (const auto& x : s) {
        if (!first) {
            os << ", ";
        }
        first = false;
        os << x;
    }
    return os << "}";
}

template <class K, class V>
std::ostream& operator<<(std::ostream& os, const std::map<K, V>& m) {
    os << "{";
    bool first = true;
    for (const auto& kv : m) {
        if (!first) {
            os << ", ";
        }
        first = false;
        os << kv.first << ": " << kv.second;
    }
    return os << "}";
}

template<class T, class U>
void AssertEqual(const T& t, const U& u, const std::string& hint)
{
    if (t != u) {
        std::ostringstream os;
        os << "Assertion failed: " << t << " != " << u << " hint: " << hint;
        throw std::runtime_error(os.str());
    }
}

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
