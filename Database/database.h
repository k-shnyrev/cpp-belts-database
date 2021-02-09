#pragma once

#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <set>

#include "date.h"
#include "node.h"

class Database {
public:
    void Add(const Date& date, const std::string& event);
    bool DeleteEvent(const Date& date, const std::string& event);
    int DeleteDate(const Date& date);
    std::set<std::string> Find(const Date& date) const;
    void Print(std::ostream& os) const;
    template <class Predicate>
    int RemoveIf(Predicate predicate);
    template <class Predicate>
    std::vector<std::string> FindIf(Predicate predicate);
    const std::string Last(const Date& date) const;
private:
    std::map<Date, std::set<std::string>> storage;
};
