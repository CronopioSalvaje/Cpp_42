

#ifndef ROBOTOMYREQUESTFORM_H
#define ROBOTOMYREQUESTFORM_H

#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
    private:
        std::string _name;
    public:
        RobotomyRequestForm(void);
        RobotomyRequestForm(std::string name);
        RobotomyRequestForm(RobotomyRequestForm const &cl);
        virtual void action() const ;
        ~RobotomyRequestForm();
        void operator=(RobotomyRequestForm const &cl);
};

#endif
