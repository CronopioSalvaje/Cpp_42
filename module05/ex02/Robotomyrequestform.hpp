#ifndef TEST_H
#define TEST_H

#include <iostream>

class Robotomyrequestform
{
    private:
        std::string _name;
    public:
        Robotomyrequestform(void);
        Robotomyrequestform(std::string name);
        Robotomyrequestform(Robotomyrequestform const &cl);
        ~Robotomyrequestform();
        void operator=(Robotomyrequestform const &cl);
};

#endif
