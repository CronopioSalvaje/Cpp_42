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
    std::string Forms[] = {"PresidentialPardonForm","RobotomyPardonFom", "ShrubberyCreationForm"};
    size_t size = sizeof(Forms) / sizeof(Forms[0]);
    for (size_t i = 0; i < size; i++)
    {
        if (Forms[i] == name)
            return(i);
    }
    return (-1);
}

AForm *Intern::makeForm(std::string name, std::string target)
{
    PresidentialPardonForm *form = new PresidentialPardonForm(target);
    (void)name;
    (void)target;
    return (form);

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
