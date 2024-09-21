#ifndef TEST_H
#define TEST_H

#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"

/**
 * ShrubberyCreationForm: Required grades: sign 145, exec 137
Create a file <target>_shrubbery in the working directory, and writes ASCII trees
inside it.
 * 
 * 
 */

class Shrubberycreationform : public AForm
{
    private:
        std::string _name;
    public:
        Shrubberycreationform(void);
        Shrubberycreationform(std::string target);
        Shrubberycreationform(Shrubberycreationform const &cl);
        virtual void action();
        ~Shrubberycreationform();
        void operator=(Shrubberycreationform const &cl);
};

#endif
