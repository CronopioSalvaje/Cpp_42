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
        std::vector<unsigned int> m_lst;
        std::vector<unsigned int> m_vec;
    public:
        PmergeMe(void);
        PmergeMe(std::vector<unsigned int> &lst);        
        PmergeMe(PmergeMe const &cl);
        ~PmergeMe();
        std::vector<pair> sliceList(std::vector<unsigned int> &lst);
        std::vector<unsigned int> sortPendants(std::vector<unsigned int> lst, 
            std::vector<pair> pairs, std::vector<unsigned int> alone);
        void insertByBinaryLimitedResearch(pair p, std::vector<unsigned int> &lst);
        void insertByBinaryResearch(std::vector<unsigned int> &lst, std::vector<unsigned int> &alone);
        template<typename T>
        bool isSortedList(const T &lst)
        {
            typename T::const_iterator it = lst.begin();
            typename T::const_iterator it2 = it;
            it2++;
            if (lst.size() <= 1)
                return true;
            for (; it2 != lst.end(); ++it, ++it2)
            {             
                if (*it > *(it2))
                    return false;
            }
            return true;
        }
        void sort();
        void setVector();
        void operator=(PmergeMe const &cl);

        template<typename T>
        void printlist(T lst, std::string const &name)
        {
            std::cout << "===PRINT "<<name<<"===" << std::endl;
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
        std::vector<unsigned int> sortList(std::vector<unsigned int> toSort);
        void sortVector();
};

#endif
