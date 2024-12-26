#pragma once

#include <string>
#include <iostream>
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
    int year;
    int month;
    int day;
    std::string d_str;
    bool operator<(const s_date& other) const {
        if (year != other.year)
            return year < other.year;
        if (month != other.month)
            return month < other.month;
        return day < other.day;
    }
} t_date;

class BitcoinExchange
{
    private:
        std::map<t_date, double> m_btcExchange;
        std::map<t_date, double> m_DB;
        BitcoinExchange(BitcoinExchange const &cl);
        BitcoinExchange &operator=(BitcoinExchange const &cl);
        void parseline(std::string &line, std::map<t_date, double> map, int ctx);
        void parseDatabase();
        void parseUserfile(std::string path);
    public:
        BitcoinExchange(std::string const &path);
        ~BitcoinExchange();

};