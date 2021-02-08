#pragma once

#include <string>

#include "date.h"

enum class Comparison {
    Less,
    LessOrEqual,
    Greater,
    GreaterOrEqual,
    Equal,
    NotEqual
};

enum class LogicalOperation {
    And,
    Or
};

class Node {
public:
    Node();
    bool Evaluate(const Date& date, const std::string& event);
    ~Node();
};

class DateComparisonNode : public Node {
    
};

class EventComparisonNode : public Node {
    
};
