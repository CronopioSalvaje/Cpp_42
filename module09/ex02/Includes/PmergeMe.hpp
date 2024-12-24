#ifndef PMERGEME_H
#define PMERGEME_H

#include <iostream>
#include "colors.hpp"
#include <list>
#include <vector>

typedef enum mode{
    DEBUG,
    NORMAL
} mode;

extern mode debug;

#define DEBUGGER(val) if (debug == DEBUG) {std::cerr << RED << "FOLLOW ME : " << val << RESET << std::endl;}

typedef struct Pair {
    unsigned int first;
    unsigned int second;
} pair;

class PmergeMe
{
    private:
        std::list<unsigned int> m_lst;
        std::vector<unsigned int> m_vec;
    public:
        PmergeMe(void);
        PmergeMe(std::list<unsigned int> &lst);        
        PmergeMe(PmergeMe const &cl);
        ~PmergeMe();
        std::list<pair> sliceList();
        void sort();
        void setVector();
        void operator=(PmergeMe const &cl);

        template<typename T>
        void printlist(T lst, std::string const &name)
        {
            std::cout << "===PRINT"<<name<<"===" << std::endl;
            typename T::iterator it;
            size_t count = 0;
            for (it = lst.begin(); it != lst.end(); ++it)
            {        
                std::cout << *it;
                if(count < lst.size() - 1)
                    std::cout << " - ";
                count++;
            }
            std::cout << std::endl;
        }
        void printlist();
        void printvector();
        void sortList();
        std::list<unsigned int> sortList(std::list<unsigned int> toSort);
        void sortVector();
};

#endif
