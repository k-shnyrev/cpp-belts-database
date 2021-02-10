#pragma once

#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

#include "date.h"
#include "node.h"

class Database {
public:
    void Add(const Date& date, const std::string& event);
    bool DeleteEvent(const Date& date, const std::string& event);
    int DeleteDate(const Date& date);
    std::set<std::string> Find(const Date& date) const;
    void Print(std::ostream& os) const;
    
    template <typename Predicate>
    int RemoveIf(Predicate p) {
        int original_size = int(storage.size());
        for(auto iter = storage.begin(); iter != storage.end(); ) {
            for (auto second_it = iter->second.begin(); second_it != iter->second.end(); ) {
                if (p(iter->first, *second_it)) {
                    second_it = iter->second.erase(second_it);
                } else {
                ++second_it;
                }
            }
            ++iter;
        }
        return original_size - int(storage.size());
    };
    
    template <typename Predicate>
    std::vector<std::string> FindIf(Predicate p) {
        std::vector<std::string> res;
        for (auto iter = storage.begin(); iter != storage.end(); ) {
            for (auto second_it = iter->second.begin(); second_it != iter->second.end(); ) {
                if (p(iter->first, *second_it)) {
                    res.push_back(*second_it);
                }
                ++second_it;
            }
            ++iter;
        }
        return {};
    };
    
    const std::string Last(const Date& date) const;
private:
    std::map<Date, std::set<std::string>> storage;
};
