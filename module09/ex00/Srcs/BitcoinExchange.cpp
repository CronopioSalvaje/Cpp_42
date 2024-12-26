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

bool isValidInRange(std::string nbr, int min, int max, t_date *d)
{
    std::stringstream ss;
    int number;
    if (!onlyDigits(nbr.c_str()))
        return false;
    ss << nbr;
    ss >> number;
    if (ss.fail())
        return false;
    switch (max)
    {
        case 12: d->month = number; break;
        case 31: d->day = number; break;    
        default: d->year = number; break;
    }
    return (number >= min && number <= max);
}

bool isValidDay(std::string date, t_date *d){
    std::string day = date.substr(8,2);
    return isValidInRange(day, 1, 31, d);
}

bool isValidMonth(std::string date, t_date *d){
    std::string month = date.substr(5,2);
    return isValidInRange(month, 1, 12, d);
}

bool isValidYear(std::string date, t_date *d)
{
    std::string year = date.substr(0,4);
    return isValidInRange(year, 2000, 2100, d);
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

bool checkDateFormat(std::string date, t_date *d)
{
    return isValidSize(date) && areSeparatorsValid(date) && isValidYear(date, d) && isValidMonth(date, d) && isValidDay(date, d);
}

std::string trim(std::string str)
{
    size_t first = str.find_first_not_of(" \t\n\r\f\v");
    size_t last =  str.find_last_not_of(" \t\n\r\f\v");
    
    if (first == std::string::npos)
        return "";
    return (str.substr(first, last - first + 1));
}

bool checkValue(std::string value, double *val, int limit)
{
    std::stringstream ss;
    ss << value;
    double d;
    ss >> d;
    if (ss.fail())
        throw GenericException("Error: Bad Input");
        return false;
    if (d < 0)
    {
        throw GenericException("Error: not a positive number");
        return false;
    }
    if (limit == USERFILE && d > 1000)
    {
        throw GenericException("Error: number too large");
        return false;
    }
    *val = d;
    return true;        
}

void BitcoinExchange::parseline(std::string &line, std::map<t_date, double> map, int ctx)
{    
    size_t pos;
    double val;
    switch (ctx)
    {
    case 0: pos = line.find(","); break;
    case 1000: pos = line.find("|"); break;
    default:
        break;
    }     
    static int lnumb = 1;
    std::string date = trim(line.substr(0, pos));
    t_date d;
    d.d_str = date;
    if(!checkDateFormat(date, &d))
    {
        std::cerr << "Error : bad format at line " << lnumb << std::endl;
        lnumb++;
        return;
    }
    lnumb++;
    std::string value = "";
    if (pos !=std::string::npos)
        value = trim(line.substr(pos + 1, std::string::npos));
    if(!checkValue(value, &val, ctx))
    {
        std::cerr << "Error : bad format at line " << lnumb << std::endl;
        lnumb++;
        return;
    }
    map.insert(std::make_pair(d, val));
}

void BitcoinExchange::parseDatabase()
{
    std::ifstream file(DB_PATH);
    if (!file || !file.is_open() || file.fail() || file.bad())
        throw FileErrorException("DB File Error");
    std::string line;
    while (std::getline(file, line))
    {
        parseline(line, m_DB, DATABASE);
    }
}

 void BitcoinExchange::parseUserfile(std::string path)
 {
    std::ifstream file(path.c_str());
    if (!file || !file.is_open() || file.fail() || file.bad())
        throw FileErrorException("File Error");
    std::string line;
    while (std::getline(file, line))
    {
        parseline(line, m_btcExchange, USERFILE);
    }
 }

BitcoinExchange::BitcoinExchange(std::string const &path)
{
    parseDatabase();
    parseUserfile(path);  
}

BitcoinExchange::~BitcoinExchange(){}