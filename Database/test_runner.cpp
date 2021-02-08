#include "test_runner.h"

template <class T>
ostream& operator << (ostream& os, const set<T>& s) {
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
ostream& operator << (ostream& os, const map<K, V>& m) {
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
void AssertEqual(const T& t, const U& u, const string& hint)
{
    if (t != u) {
        ostringstream os;
        os << "Assertion failed: " << t << " != " << u << " hint: " << hint;
        throw runtime_error(os.str());
    }
}

template <class TestFunc>
void TestRunner::RunTest(TestFunc func, const string& test_name) {
    try {
        func();
        cerr << test_name << " OK\n";
    } catch (runtime_error& e) {
        ++fail_count;
        cerr << test_name << " fail: " << e.what() << '\n';
    }
}

TestRunner::~TestRunner() {
    if (fail_count > 0) {
        cerr << fail_count << " unit tests failed. Terminate\n";
        exit(1);
    }
}
