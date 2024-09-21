#include "../Includes/RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>  

RobotomyRequestForm::RobotomyRequestForm():AForm::AForm("Robotomy Request Form", 72, 45)
{    
    this->setTarget("unknown");
}

RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm::AForm("Robotomy Request Form", 72, 45)
{
    this->setTarget(target);
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &cl): AForm::AForm("Robotomy Request Form", 72, 45)
{    
    this->setTarget(cl.getTarget());
}

void RobotomyRequestForm::operator=(RobotomyRequestForm const &cl)
{
    this->setExecGrade(45);
    this->setSignGrade(72);
    this->setTarget(cl.getTarget());
}


RobotomyRequestForm::~RobotomyRequestForm()
{
   
}

void RobotomyRequestForm::action() const
{
    srand(time(0));
    int randomInRange = 0 + rand() % (100 - 0 + 1);
    
    std::cout << "bzzz bzzz !! BZZZ BZZZ ! BZZZZZ !!!!" << std::endl 
        <<"rrrrrrRRRRRRRRRRRRRRRrrrrRRRRRRRrRRRRRRrrrrrr BBBrrrrrrrrrrrrrrrrrrrrRRRRRrrRRRrRRRRRRRRRR";
    if (randomInRange > 50)
        std::cout << std::endl << this->getTarget() << " has been robotomized !!!" << std::endl;
    else
        std::cout << std::endl << "Robotomy failed on "<< this->getTarget() << " !!!" << std::endl;


}

