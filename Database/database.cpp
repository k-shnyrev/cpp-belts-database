#include "database.h"

void Database::Add(const Date& date, const std::string& event) {
    if (storage_[date].count(event) == 0) {
        storage[date].push_back(event);
        storage_[date].insert(event);
    }
}

bool Database::DeleteEvent(const Date& date, const std::string& event) {
    bool res = false;
    if (storage.count(date) > 0) {
        if (storage_.at(date).count(event) > 0) {
            storage[date] = std::vector(storage[date].begin(), std::remove(storage[date].begin(), storage[date].end(), event));
            storage_[date].erase(event);
            res = true;
        }
    }
    if (storage.count(date) > 0) {
        if (storage.at(date).size() == 0) {
            storage.erase(date);
            storage_.erase(date);
        }
    }
    return res;
}

int Database::DeleteDate(const Date& date) {
    if (storage.count(date) == 0) {
        return 0;
    }
    else {
        const int event_count = int(storage[date].size());
        storage.erase(date);
        storage_.erase(date);
        return event_count;
    }
}

std::vector<std::string> Database::Find(const Date& date) const {
    if (storage.count(date) > 0) {
        return storage.at(date);
    }
    else {
        return {};
    }
}

void Database::Print(std::ostream& os) const {
    for (const auto& item : storage) {
        for (const std::string& event : item.second) {
            os << item.first << " " << event << std::endl;
        }
    }
}

const std::string Database::Last(const Date& date) const {
    std::ostringstream oss;
    auto res = storage.upper_bound(date);
    if (res != storage.begin()) {
        res = prev(res);
        oss << res->first << " " << res->second.back();
    }
    else {
        oss << "No entries";
    }
    return oss.str();
}


std::ostream& operator<<(std::ostream& os, const std::pair<Date, std::string>& record) {
    return os << record.first << " " << record.second;
}
