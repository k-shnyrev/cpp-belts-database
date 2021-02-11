#include "node.h"

Node::Node() {
    // to do
}

bool Node::Evaluate(const Date& date, const std::string&) {
    return true;
}

bool DateComparisonNode::Evaluate(const Date& date, const std::string& event) {
    if (cmp_ == Comparison::Less) {
        return date < date_;
    }
    else if (cmp_ == Comparison::LessOrEqual) {
        return date <= date_;
    }
    else if (cmp_ == Comparison::Greater) {
        return date > date_;
    }
    else if (cmp_ == Comparison::GreaterOrEqual) {
        return date >= date_;
    }
    else if (cmp_ == Comparison::Equal) {
        return date == date_;
    }
    else if (cmp_ == Comparison::NotEqual) {
        return date != date_;
    }
    return true;
}

bool EventComparisonNode::Evaluate(const Date& date, const std::string& event) {
    if (cmp_ == Comparison::Less) {
        return event < value_;
    } else if (cmp_ == Comparison::LessOrEqual) {
        return event <= value_;
    } else if (cmp_ == Comparison::Greater) {
        return event > value_;
    } else if (cmp_ == Comparison::GreaterOrEqual) {
        return event >= value_;
    } else if (cmp_ == Comparison::Equal) {
        return event == value_;
    } else if (cmp_ == Comparison::NotEqual) {
        return event != value_;
    }
    return true;
}

bool LogicalOperationNode::Evaluate(const Date& date, const std::string& event) {
    if (logical_operation_ == LogicalOperation::And) {
        return left_->Evaluate(date, event) && right_->Evaluate(date, event);
    } else if (logical_operation_ == LogicalOperation::Or) {
        return left_->Evaluate(date, event) || right_->Evaluate(date, event);
    }
    return true;
}
