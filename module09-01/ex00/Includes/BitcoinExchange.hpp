#pragma once

#include <string>
#include <iostream>
#include <iomanip>
#include <climits>
#include "colors.hpp"
#include <fstream>
#include <sstream>
#include "cstdlib"
#include <map>

#define NO_LIMIT 0
#define LIMIT 1000
#define DB_PATH "Includes/data.csv"
#define DATABASE 0
#define USERFILE 1000

typedef struct s_date {
    size_t index;
    int year;
    int month;
    int day;
    std::string d_str;
    bool operator<(const s_date& other) const {
        if (year != other.year)
            return year < other.year;
        if (month != other.month)
            return month < other.month;
        if (day != other.day)
            return day < other.day;
        return index < other.index; 
    }
    bool operator==(const s_date& other) const {
        return year == other.year 
           && month == other.month 
           && day == other.day;
    }
    bool operator>(const s_date& other) const {
        return other < *this;
    }
    bool operator<=(const s_date& other) const {
        return !(other < *this);
    }
    bool operator>=(const s_date& other) const {
        return (other < *this || other == *this);
    }
} t_date;

class BitcoinExchange
{
    private:
        std::map<t_date, double> m_btcExchange;
        std::map<t_date, double> m_DB;
        BitcoinExchange(BitcoinExchange const &cl);
        BitcoinExchange &operator=(BitcoinExchange const &cl);
        void parseline(std::string &line, std::map<t_date, double> &map, int ctx);
        void parseDatabase();
        void parseUserfile(std::string path);
        void printDBase(std::map<t_date, double>DB);
        double getRate(std::pair<t_date, double> &pair);
        void process(std::pair<t_date, double> pair);
    public:
        BitcoinExchange(std::string const &path);
        ~BitcoinExchange();

};