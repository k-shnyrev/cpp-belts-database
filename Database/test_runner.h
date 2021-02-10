//#pragma once
//
//#include <sstream>
//#include <exception>
//#include <iostream>
//#include <string>
//#include <map>
//#include <set>
//#include <vector>
//
//using namespace std;
//
//template <class T>
//ostream& operator << (ostream& os, const set<T>& s);
//
//template <class K, class V>
//ostream& operator << (ostream& os, const map<K, V>& m);
//
//template<class T, class U>
//void AssertEqual(const T& t, const U& u, const string& hint);
//
//void Assert(const bool b, const string& hint);
//
//class TestRunner {
//public:
//    template <class TestFunc>
//    void RunTest(TestFunc func, const string& test_name);
//
//    ~TestRunner();
//
//private:
//  int fail_count = 0;
//};
//
//template<class T, class U>
//bool operator==(const std::vector<T>& left, const std::vector<U>& right);
//
//template<class T, class U>
//bool operator!=(const std::vector<T>& left, const std::vector<U>& right);
#include <sstream>
#include <exception>
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <vector>

template <class T>
std::ostream& operator<<(std::ostream& os, const std::set<T>& s);

template <class K, class V>
std::ostream& operator<<(std::ostream& os, const std::map<K, V>& m);

template<class T, class U>
void AssertEqual(const T& t, const U& u, const std::string& hint);

void Assert(bool b, const std::string& hint);

class TestRunner {
public:
    template <class TestFunc>
    void RunTest(TestFunc func, const std::string& test_name) {
        try {
            func();
            std::cerr << test_name << " OK" << std::endl;
        }
        catch (std::runtime_error& e) {
            ++fail_count;
            std::cerr << test_name << " fail: " << e.what() << std::endl;
        }
    }

    ~TestRunner() {
        if (fail_count > 0) {
            std::cerr << fail_count << " unit tests failed. Terminate" << std::endl;
            exit(1);
        }
    }

private:
    int fail_count = 0;
};

template<class T, class U>
bool operator==(const std::vector<T>& left, const std::vector<U>& right);

template<class T, class U>
bool operator!=(const std::vector<T>& left, const std::vector<U>& right);
