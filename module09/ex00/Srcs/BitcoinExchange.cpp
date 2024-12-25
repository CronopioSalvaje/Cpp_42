#include "../Includes/BitcoinExchange.hpp"
#include "../Includes/FileErrorException.hpp"
#include "../Includes/InvalidFormatException.hpp"
#include "../Includes/GenericException.hpp"

bool onlyDigits(const char *str)
{
    int i = 0;
    while(str[i])
    {
        if (isdigit(str[i]) == 0)
            return false;
        i++;
    }
    return true;
}

bool isValidInRange(std::string nbr, int min, int max)
{
    std::stringstream ss;
    int number;
    if (!onlyDigits(nbr.c_str()))
        return false;
    ss << nbr;
    ss >> number;
    if (ss.fail())
        return false;
    return (number >= min && number <= max);
}

bool isValidDay(std::string date){
    std::string day = date.substr(8,2);
    return isValidInRange(day, 1, 31);
}

bool isValidMonth(std::string date){
    std::string month = date.substr(5,2);
    return isValidInRange(month, 1, 12);
}

bool isValidYear(std::string date)
{
    std::string year = date.substr(0,4);
    return isValidInRange(year, 2000, 2100);
}

bool isValidSize(std::string date)
{
    return (date.size() == 10);
}

bool areSeparatorsValid(std::string date)
{
    if (date.size() < 8)
        return false;
    return (date[4] == '-' && date[7] == '-');
}

bool checkDateFormat(std::string date)
{
    return isValidSize(date) && areSeparatorsValid(date) && isValidYear(date) && isValidMonth(date) && isValidDay(date);
}

void BitcoinExchange::parseline(std::string &line, std::map<std::string, float> map)
{
    size_t pos = line.find(",");
    static int lnumb = 1;
    std::string date = line.substr(0, pos);
    if(!checkDateFormat(date))
        std::cerr << "Error : bad format at line " << lnumb << std::endl;
    lnumb++;
    std::string value = "";
    if (pos !=std::string::npos)
        value = line.substr(pos + 1, std::string::npos);
    std::cout << BOLD_BLUE << date << "::" << value << std::endl;
}

void BitcoinExchange::parseDatabase()
{
    std::ifstream file(DB_PATH);
    if (!file || !file.is_open() || file.fail() || file.bad())
        throw FileErrorException("DB File Error");
    std::string line;
    while (std::getline(file, line))
    {
        parseline(line, m_DB);
    }
}

BitcoinExchange::BitcoinExchange(std::string const &path)
{
    parseDatabase();
    std::ifstream file(path.c_str());
    if (!file || !file.is_open() || file.fail() || file.bad())
        throw FileErrorException("File Error");
    std::string line;
    while (std::getline(file, line))
    {
        parseline(line, m_btcExchange);
    }
}

BitcoinExchange::~BitcoinExchange(){}