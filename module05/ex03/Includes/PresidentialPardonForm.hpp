#ifndef PRESIDENTIALFORM_HPP
#define PRESIDENTIALFORM_HPP

#include <iostream>
#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
    private:
    public:
        PresidentialPardonForm(void);
        PresidentialPardonForm(std::string target);
        PresidentialPardonForm(PresidentialPardonForm const &cl);
        virtual void action() const ;
        virtual ~PresidentialPardonForm();
        void operator=(PresidentialPardonForm const &cl);
};

#endif
