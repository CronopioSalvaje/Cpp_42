#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
class AForm;

class Intern
{
    private:
    public:
        Intern(void);
        Intern(Intern const &cl);
        int getFormIndex(std::string name);
        AForm *makeForm(std::string name, std::string target);
        ~Intern();
        void operator=(Intern const &cl);
};

#endif
