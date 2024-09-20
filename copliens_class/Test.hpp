#ifndef TEST_H
#define TEST_H

#include <iostream>

class Test
{
    private:
        std::string _name;
    public:
        Test(void);
        Test(std::string name);
        Test(Test const &cl);
        ~Test();
        void operator=(Test const &cl);
};

#endif
