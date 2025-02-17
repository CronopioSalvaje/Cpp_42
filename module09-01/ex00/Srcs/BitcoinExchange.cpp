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
        case 28:
        case 29:
        case 30:
        case 31: d->day = number; break;    
        default: d->year = number; break;
    }
    return (number >= min && number <= max);
}

int getnbfromstr(std::string nbr)
{
    std::stringstream ss;
    int number = 0;
    ss << nbr;
    ss >> number;
    if (ss.fail())
        return INT_MAX;
    return number;
}

int febdaysinbissextilyears(int year)
{
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        return 29;
    return 28;
}

int dayinmonth(std::string month, std::string year)
{
    int m = getnbfromstr(month);
    int y = getnbfromstr(year);
    switch (m)
    {
        case 2: return febdaysinbissextilyears(y);
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12: return 31; break;
        case 4:
        case 6:
        case 9:
        case 11: return 30; break;
        default: return INT_MAX; break;
    }
    return INT_MAX;

}

bool isValidDay(std::string date, t_date *d){
    std::string month = date.substr(5,2);
    std::string day = date.substr(8,2);
    std::string year = date.substr(0,4);

    int max = dayinmonth(month, year);
    if (max == INT_MAX)
        return false;
    return isValidInRange(day, 1, max, d);
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
    ss >> *val;
    if (ss.fail())
    {
        throw GenericException("Error: Bad Input");
        return false;
    }
    if (*val < 0)
    {
        throw GenericException("Error: not a positive number");
        return false;
    }
    if (limit == USERFILE && *val > 1000)
    {
        throw GenericException("Error: number too large");
        return false;
    }
    return true;        
}

double BitcoinExchange::getRate(std::pair<t_date, double> &pair)
{
    (void) pair;
    std::map<t_date, double>::reverse_iterator it;
    it = m_DB.rbegin();
    for (; it != m_DB.rend(); ++it)
    {  
        if (pair.first >= it->first)        
            break;
    }
    return it->second;
}

void BitcoinExchange::process(std::pair<t_date, double> pair)
{
    float val = static_cast<float>(pair.second * getRate(pair));
    std::cout << pair.first.d_str << " => " << pair.second << " = " << val << std::endl;
}

void BitcoinExchange::parseline(std::string &line, std::map<t_date, double> &map, int ctx)
{    
    size_t pos;
    double val = 0;
    switch (ctx)
    {
        case 0: pos = line.find(","); break;
        case 1000: pos = line.find("|"); break;
        default: break;
    }     
    static int lnumb = 1;
    if (line == "RESET")
    {
        lnumb = 1;
        return;
    }
    std::string date = trim(line.substr(0, pos));
    t_date d;
    d.d_str = date;
    if(!checkDateFormat(date, &d))
    {
        if (lnumb > 1 && line.find("date") == std::string::npos)
            std::cerr << "Error: bad input => " << date << std::endl;
        lnumb++;
        return;
    }
    std::string value = "";
    if (pos !=std::string::npos)
        value = trim(line.substr(pos + 1, std::string::npos));
    try{
        if (checkValue(value, &val, ctx))
        {
            d.index = lnumb;
            std::pair<t_date, double> record;
            record = std::make_pair(d, val);            
            if (ctx == USERFILE)
                process(record);
            else
                map.insert(record);
        }
        lnumb++;
    }
    catch(GenericException &e)
    {
        std::cerr << e.what() << std::endl;
        lnumb++;
        return;
    }
}

void BitcoinExchange::printDBase(std::map<t_date, double>DB)
{
    std::map<t_date, double>::iterator it;
    for (it = DB.begin(); it != DB.end(); ++it)
    {
        std::cout << GREEN << it->first.index << " / " << it->first.d_str << "   " << BLUE << it->second << RESET << std::endl;
    }

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
    std::string line_count = "RESET";
    parseline(line_count, m_btcExchange, USERFILE);
    std::ifstream file(path.c_str());
    if (!file || !file.is_open() || file.fail() || file.bad())
        throw FileErrorException("Error: could not open file.");
    std::string line;
    while (std::getline(file, line))
    {
        parseline(line, m_btcExchange, USERFILE);
    }
 }

BitcoinExchange::BitcoinExchange(std::string const &path)
{
    parseDatabase();
    //printDBase(m_DB);
    parseUserfile(path);
}

BitcoinExchange::~BitcoinExchange(){}