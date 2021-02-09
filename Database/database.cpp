#include "database.h"

void Database::Add(const Date& date, const std::string& event) {
    storage[date].insert(event);
}

bool Database::DeleteEvent(const Date& date, const std::string& event) {
    if (storage.count(date) > 0 && storage[date].count(event) > 0) {
        storage[date].erase(event);
        return true;
    }
    return false;
}

int Database::DeleteDate(const Date& date) {
    if (storage.count(date) == 0) {
        return 0;
    }
    else {
        const int event_count = storage[date].size();
        storage.erase(date);
        return event_count;
    }
}

std::set<std::string> Database::Find(const Date& date) const {
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

template <class Predicate>
int Database::RemoveIf(Predicate predicate) {
    // to do, check predicate type
    return {};
}

template <class Predicate>
std::vector<std::string> Database::FindIf(Predicate predicate) {
    // to do, check predicate type
    return {};
}

const std::string Database::Last(const Date& date) const {
    // to do
    return {};
}
