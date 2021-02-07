#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

// const vector<int> MONTHS {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
constexpr char SEP {'-'};

class Date {
public:
    int GetYear() const {
        return year;
    }
    int GetMonth() const {
        return month;
    }
    int GetDay() const {
        return day;
    }
    Date() {
        day = 1;
        month = 1;
        year = 0;
    }
    Date(int d, int m, int y) {
        if (m < 1 || m > 12) {
            throw runtime_error("Month value is invalid: " + to_string(m));
        }
        if (d < 1 || d > 31) {
            throw runtime_error("Day value is invalid: " + to_string(d));
        }
        day = d;
        month = m;
        year = y;
    }
    int totalDays() const {
        int res = (year - 1) * 365;
        for (int m = 0; m < month - 1; ++m) {
            //res += MONTHS[m];
            res += 31;
        }
        res += day;
        return res;
    }
private:
    int day;
    int month;
    int year;
};

bool operator<(const Date& a, const Date& b) {
    return a.totalDays() < b.totalDays();
}

istream& operator>>(istream& is, Date& val) {
    int day, month, year;
    char sep1, sep2, c;
    string input;
    is >> input;
    stringstream ss(input);
    ss >> year >> sep1 >> month >> sep2 >> day;
    if (!ss || sep1 != SEP || sep2 != SEP || ss >> c) {
        is.setstate(ios::failbit);
        throw runtime_error("Wrong date format: " + input);
    }
    val = Date(day, month, year);
    return is;
}

ostream& operator<<(ostream& os, const Date& val) {
    os.fill('0');
    return os << setw(4) << val.GetYear() << SEP << setw(2) << val.GetMonth() << SEP << setw(2) << val.GetDay();
}

class Database {
public:
    void AddEvent(const Date& date, const string& event) {
        base[date].insert(event);
    }
    
    bool DeleteEvent(const Date& date, const string& event) {
        if (base[date].count(event) > 0) {
            base[date].erase(event);
            return true;
        }
        return false;
    }
    int DeleteDate(const Date& date) {
        const int res = int(base[date].size());
        base[date].clear();
        return res;
    }
    set<string> Find(const Date& date) const {
        set<string> res;
        if (base.count(date) > 0) {
            res = base.at(date);
        }
        return res;
    }
    void Print() const {
        for (const auto& [date, events] : base) {
            for (const auto& event : events) {
                cout << date << ' ' << event << '\n';
            }
        }
    }
private:
    map<Date, set<string>> base;
};

int main(int argc, const char * argv[]) {
    try {
        Database db;
        string command;
        while (getline(cin, command)) {
            if (command == "") {
                continue;
            }
            stringstream ss(command);
            string comm;
            ss >> comm;
            if (comm == "Add") {
                Date date;
                string event;
                if (ss >> date >> event) {
                    db.AddEvent(date, event);
                } else {
                    throw runtime_error("Unknown command: " + comm);
                }
            } else if (comm == "Del") {
                Date date;
                string event;
                if (ss >> date) {
                    if (ss >> event) {
                        if (db.DeleteEvent(date, event)) {
                            cout << "Deleted successfully\n";
                        } else {
                            cout << "Event not found\n";
                        }
                    } else {
                        cout << "Deleted " << db.DeleteDate(date) << " events\n";
                    }
                } else {
                    throw runtime_error("Unknown command: " + comm);
                }
            } else if (comm == "Find") {
                Date date;
                if (ss >> date) {
                    for (const auto& event : db.Find(date)) {
                        cout << event << '\n';
                    }
                } else {
                    throw runtime_error("Unknown command: " + comm);
                }
            } else if (comm == "Print") {
                db.Print();
            } else {
                throw runtime_error("Unknown command: " + comm);
            }
        }
        return 0;
    }
    catch (const runtime_error& e) {
        cout << e.what() << '\n';
    }
}
