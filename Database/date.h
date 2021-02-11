#pragma once

#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>
#include <iomanip>
#include <sstream>

class Date {
public:
    Date(int new_year, int new_month, int new_day);

    int GetYear() const;
    int GetMonth() const;
    int GetDay() const;

private:
    int year;
    int month;
    int day;
};

Date ParseDate(std::istream& is);

bool operator<(const Date& lhs, const Date& rhs);

bool operator<=(const Date& lhs, const Date& rhs);

bool operator>(const Date& lhs, const Date& rhs);

bool operator>=(const Date& lhs, const Date& rhs);

bool operator==(const Date& lhs, const Date& rhs);

bool operator!=(const Date& lhs, const Date& rhs);

std::ostream& operator<<(std::ostream& stream, const Date& date);
