#include "database.h"

void Database::Add(const Date& date, const std::string& event) {
    // to do
}

void Database::Print(std::ostream& cout) const {
    // to do
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
