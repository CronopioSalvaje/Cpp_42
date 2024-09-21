#ifndef TEST_H
#define TEST_H

#include <iostream>

class Presidentialpardonform
{
    private:
        std::string _name;
    public:
        Presidentialpardonform(void);
        Presidentialpardonform(std::string name);
        Presidentialpardonform(Presidentialpardonform const &cl);
        ~Presidentialpardonform();
        void operator=(Presidentialpardonform const &cl);
};

#endif
