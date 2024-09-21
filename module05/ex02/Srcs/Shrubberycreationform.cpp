#include "../Includes/Shrubberycreationform.hpp"
#include "../Includes/Bureaucrat.hpp"
#include  <fstream>

Shrubberycreationform::Shrubberycreationform(): _name("Shrubbery Creation Form")
{
    this->setExecGrade(137);
    this->setSignGrade(145);
    this->setTarget("undefined");
}

Shrubberycreationform::Shrubberycreationform(std::string target): _name("Shrubbery Creation Form")
{
    this->setExecGrade(137);
    this->setSignGrade(145);
    this->setTarget(target);
}

Shrubberycreationform::Shrubberycreationform(Shrubberycreationform const &cl): AForm::AForm("Shrubbery Creation Form", 145, 137)
{    
    this->setTarget(cl.getTarget());
}

Shrubberycreationform::~Shrubberycreationform()
{
   
}

void Shrubberycreationform::action()
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

void Shrubberycreationform::operator=(Shrubberycreationform const &cl)
{
    this->setExecGrade(137);
    this->setSignGrade(145);
    this->setTarget(cl.getTarget());
}
