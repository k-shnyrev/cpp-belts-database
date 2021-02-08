#pragma once

#include <string>
#include <iostream>
#include <vector>

#include "date.h"
#include "node.h"

class Database {
public:
    void Add(const Date& date, const std::string& event);
    void Print(std::ostream& cout) const;
    template <class Predicate>
    int RemoveIf(Predicate predicate);
    template <class Predicate>
    std::vector<std::string> FindIf(Predicate predicate);
    const std::string Last(const Date& date) const;
};
