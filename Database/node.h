#pragma once

#include <string>
#include <memory>

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
    virtual bool Evaluate(const Date& date, const std::string& event);
};

class EmptyNode : public Node {
};


class DateComparisonNode : public Node {
public:
    DateComparisonNode(const Comparison& cmp, const Date& date) :
        cmp_{ cmp }, date_{ date } {
    }
    bool Evaluate(const Date& date, const std::string& event) override;
private:
    const Comparison cmp_;
    const Date date_;
};

class EventComparisonNode : public Node {
public:
    EventComparisonNode(const Comparison& cmp, const std::string& value) :
        cmp_{ cmp }, value_{ value } {
    };
    bool Evaluate(const Date& date, const std::string& event) override;
private:
    const Comparison cmp_;
    const std::string value_;
};

class LogicalOperationNode : public Node {
public:
    LogicalOperationNode(const LogicalOperation& logical_operation, const std::shared_ptr<Node> left, const std::shared_ptr<Node> right) :
        logical_operation_{ logical_operation }, left_{ left }, right_{ right } {
    };
    bool Evaluate(const Date& date, const std::string& event) override;
private:
    const LogicalOperation logical_operation_;
    const std::shared_ptr<Node> left_;
    const std::shared_ptr<Node> right_;
};
