#include "../Includes/Intern.hpp"
#include "../Includes/PresidentialPardonForm.hpp"
#include "../Includes/RobotomyRequestForm.hpp"
#include "../Includes/ShrubberyCreationForm.hpp"
#include "../Includes/AForm.hpp"


Intern::Intern()
{    
}

int Intern::getFormIndex(std::string name)
{
    std::string Forms[] = {"Presidential Pardon","Robotomy Pardon", "Shrubbery Creation"};
    size_t size = sizeof(Forms) / sizeof(Forms[0]);
    for (size_t i = 0; i < size; i++)
    {
        if (Forms[i] == name)
            return(i);
    }
    return (-1);
}

void Intern::msg(std::string name)
{
    std::cout << "Intern create " << name << std::endl;
}

AForm *Intern::makeForm(std::string name, std::string target)
{
    switch (getFormIndex(name))
    {
        case 0: msg (name); return new PresidentialPardonForm(target); break;
        case 1: msg (name); return new RobotomyRequestForm(target); break;
        case 2: msg (name); return new ShrubberyCreationForm(target); break;    
        default: std::cout << "Invalid Form name" << std::endl; return (NULL); break;
    }
    return (NULL);
}

Intern::Intern(Intern const &cl)
{
    (void)cl;
}

Intern::~Intern()
{
   
}

void Intern::operator=(Intern const &cl)
{
    (void) cl;
}
