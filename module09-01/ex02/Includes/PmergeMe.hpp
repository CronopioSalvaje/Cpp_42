#ifndef PMERGEME_H
#define PMERGEME_H

#include <iostream>
#include "colors.hpp"
#include <list>
#include <algorithm>
#include <vector>
#include <ctime>

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
        PmergeMe(std::vector<unsigned int> &vec);        
        PmergeMe(PmergeMe const &cl);
        ~PmergeMe();
        std::vector<unsigned int> sortPendants(std::vector<unsigned int> &lst, 
            std::vector<pair> pairs);
        void insertByBinaryLimitedResearch(pair p, std::vector<unsigned int> &lst);
        std::vector<size_t> getJacobsthalSuite(size_t size);
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
        void setList();
        void operator=(PmergeMe const &cl);
        void debugSliced(std::vector<pair> const &v)
        {
            std::vector<pair>::const_iterator it = v.begin();
            for (;it != v.end(); ++it)
            {
                std::cout << BOLD_BLUE << "pair : ("<< it->first <<":"<<it->second<<")" << RESET << std::endl;
            }

        }

        template<typename T>
        void swap(T *a, T *b)
        {
            T temp;
            temp = *a;
            *a = *b;
            *b = temp;
        }
        template <typename Container>
        std::vector<pair> sliceList(Container &lst)
        {
            std::vector<pair> pairs;
            size_t limit = 0;
            if (lst.size() % 2 != 0)
                limit = 1;
            while (lst.size() > limit)
            {
                pair p;
                p.first = lst.back();
                lst.pop_back();
                p.second = lst.back();
                lst.pop_back();
                if (p.first < p.second)
                    swap(&p.first, &p.second);
                pairs.push_back(p);
            }
            return pairs;
        }

        template<typename T>
        void printlist(T lst, std::string const &label)
        {
            typename T::iterator it;
            size_t count = 0;
            std::cout << label;
            for (it = lst.begin(); it != lst.end(); ++it)
            {        
                std::cout << *it;
                if(count < lst.size() - 1)
                    std::cout << " ";
                count++;
            }
            std::cout << std::endl;
        }
        void printvector();
        std::list<unsigned int> sortPendantsList(std::list<unsigned int> &lst, std::vector<pair> pairs);
        std::list<unsigned int> sortList(std::list<unsigned int> lst);
        std::vector<unsigned int> sortVector(std::vector<unsigned int> vec);  
        void insertByBinaryLimitedResearchList(pair p, std::list<unsigned int> &lst);
        void insertByBinaryResearchList(std::list<unsigned int> &lst, std::list<unsigned int> &alone);
        unsigned int getElementAtIndex(const std::list<unsigned int>& lst, size_t index);
};

#endif
