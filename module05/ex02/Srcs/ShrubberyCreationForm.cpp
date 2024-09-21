#include "../Includes/ShrubberyCreationForm.hpp"
#include "../Includes/Bureaucrat.hpp"
#include  <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(): AForm::AForm("Shrubbery Creation Form")
{
    this->setExecGrade(137);
    this->setSignGrade(145);
    this->setTarget("undefined");
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): AForm::AForm("Shrubbery Creation Form", 145, 137)
{
    this->setTarget(target);
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &cl): AForm::AForm("Shrubbery Creation Form", 145, 137)
{    
    this->setTarget(cl.getTarget());
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
   
}

void ShrubberyCreationForm::action(void) const
{
    std::ofstream out((this->getTarget() + "_shrubbery").c_str());
    std::ifstream in("Includes/trees/1");
    std::string line;
    while (std::getline(in, line))
    {
        out << line << std::endl;
    }
    in.close();
    out.close();

}

void ShrubberyCreationForm::operator=(ShrubberyCreationForm const &cl)
{
    this->setExecGrade(137);
    this->setSignGrade(145);
    this->setTarget(cl.getTarget());
}
