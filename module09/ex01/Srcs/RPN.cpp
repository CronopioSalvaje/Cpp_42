#include "../Includes/RPN.hpp"
#include "../Includes/InvalidExpressionException.hpp"

RPN::RPN(RPN const &cl)
{
    *this = cl;
}

RPN &RPN::operator=(RPN const &cl)
{
    stack = cl.stack;
    return *this;
}

bool RPN::areSeparatedVals(std::string const & str)
{
    size_t i = 0;
    bool sep = true;    
    while (str[i])
    {

        if (str[i] == ' ')
            sep = true;
        else
        {
            if (sep == true)
                toogle(&sep);
            else
                return false;
        }
        i++;
    }
    return true;
}

void RPN::checkExpression()
{
    if (m_exp.size() == 0)
        throw InvalidExpressionException("Void Expression");
    else if (m_exp.size() < 2)
        throw InvalidExpressionException("not enougth data");
    if (!areValidChars(m_exp))
        throw InvalidExpressionException("Invalid Characters");
    if (!areSeparatedVals(m_exp))
        throw InvalidExpressionException("not separated elements");
}


bool RPN::isValidChar(char c)
{
    size_t i = 0;
    char test[] = "0123456789-+/* ";
    while(test[i] != '\n')
    {
        if (test[i] == c)
            return true;
        i++;
    }
    return false;
}


bool RPN::areValidChars(std::string str)
{
    size_t i = 0;
    while(str[i++])
    {
        if (!isValidChar(str[i]))
            return false;
    }
    return true;
}

void RPN::executeExpression()
{

}

RPN::RPN(std::string const &exp): m_exp(trim(exp))
{
    std::cout << YELLOW << m_exp << RESET << std::endl;
    try
    {
        checkExpression();
        executeExpression();
    }
    catch (InvalidExpressionException &e)
    {
        std::cerr << e.what() << std::endl;
    }
}

RPN::~RPN(){}
