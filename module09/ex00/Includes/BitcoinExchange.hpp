#pragma once

#include <string>
#include <iostream>
#include "colors.hpp"
#include <fstream>
#include <sstream>
#include "cstdlib"
#include <map>

#define DB_PATH "Includes/data.csv"

class BitcoinExchange
{
    private:
        std::map<std::string, float> m_btcExchange;
        std::map<std::string, float> m_DB;
        BitcoinExchange(BitcoinExchange const &cl);
        BitcoinExchange &operator=(BitcoinExchange const &cl);
        void parseline(std::string &line, std::map<std::string, float> map);
        void parseDatabase();
    public:
        BitcoinExchange(std::string const &path);
        ~BitcoinExchange();

};