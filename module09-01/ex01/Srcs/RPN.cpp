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
        throw InvalidExpressionException("Invalid characters");
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
    if (str.find_first_not_of(" 0123456789+-*/") != std::string::npos)
        return false;
    return true;
}


void RPN::exec(char c)
{
    int b = stack.top();
    stack.pop();
    int a =  stack.top();
    stack.pop();
    int result = 0;
    switch (c)
    {
        case '+': result = a + b; break;
        case '-': result = a - b; break;
        case '/': if (b == 0) 
                    throw InvalidExpressionException("impossible division by 0");
                  result = a / b;
                  break;
        case '*': result = a * b; break;
    
    default:
        break;
    }
    stack.push(result);

}

void RPN::executeExpression()
{
    size_t i = 0;
    while (i < m_exp.size())
    {
        if (isdigit(m_exp[i]) > 0)
        {
            int nb = getNumberFromChar(m_exp[i]); 
            stack.push(nb);
        }
        else if (m_exp[i] != ' ')
        {
            if (stack.size() >= 2)
                exec(m_exp[i]);
            else
            {
                throw InvalidExpressionException ("Missing number to complete operation");
            }
        }
        i++;
    }
    if (stack.size() == 1)
        std::cout << stack.top() << std::endl;        
    else
        throw InvalidExpressionException("Stack is not empty - operators missing to procede");
}

RPN::RPN(std::string const &exp): m_exp(trim(exp))
{
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