#include "../Includes/PresidentialPardonForm.hpp"


PresidentialPardonForm::PresidentialPardonForm():AForm::AForm("Presidential Pardon Form", 25, 5)
{    
    this->setTarget("unknown");
}

PresidentialPardonForm::PresidentialPardonForm(std::string target): AForm::AForm("Presidential Pardon Form", 25, 5)
{
    this->setTarget(target);
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &cl):AForm::AForm("Presidential Pardon Form", 25, 5)
{    
    this->setTarget(cl.getTarget());
}

PresidentialPardonForm::~PresidentialPardonForm()
{
   
}

void PresidentialPardonForm::action(void) const
{
   std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox !" << std::endl;
}

void PresidentialPardonForm::operator=(PresidentialPardonForm const &cl)
{
    this->setExecGrade(5);
    this->setSignGrade(25);
    this->setTarget(cl.getTarget());
}
