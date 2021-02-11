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
    std::vector<std::string> Find(const Date& date) const;
    void Print(std::ostream& os) const;
    
    template <typename Predicate>
    int RemoveIf(Predicate p) {
        int res = 0;
        for(auto iter = storage.begin(); iter != storage.end(); ) {
            for (auto second_it = iter->second.begin(); second_it != iter->second.end(); ) {
                if (p(iter->first, *second_it)) {
                    storage_.at(iter->first).erase(*second_it);
                    second_it = iter->second.erase(second_it);
                    ++res;
                } else {
                    ++second_it;
                }
            }
            if (iter->second.size() > 0) {
                ++iter;
            } else {
                storage_.erase(iter->first);
                iter = storage.erase(iter);
            }
        }
        return res;
    };
    
    template <typename Predicate>
    std::vector<std::pair<Date, std::string>> FindIf(Predicate p) const {
        std::vector<std::pair<Date, std::string>> res;
        for (auto iter = storage.begin(); iter != storage.end(); ) {
            for (auto second_it = iter->second.begin(); second_it != iter->second.end(); ) {
                if (p(iter->first, *second_it)) {
                    res.push_back(std::make_pair(iter->first, *second_it));
                }
                ++second_it;
            }
            ++iter;
        }
        return res;
    };
    
    const std::string Last(const Date& date) const;
private:
    std::map<Date, std::vector<std::string>> storage;
    std::map<Date, std::set<std::string>> storage_;
};

std::ostream& operator<<(std::ostream& os, const std::pair<Date, std::string>& record);
