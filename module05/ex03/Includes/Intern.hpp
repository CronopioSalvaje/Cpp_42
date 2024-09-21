#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
class AForm;

class Intern
{
    private:
        int getFormIndex(std::string name);
    public:
        Intern(void);
        Intern(Intern const &cl);
        void msg(std::string name);
        AForm *makeForm(std::string name, std::string target);
        ~Intern();
        void operator=(Intern const &cl);
};

#endif
