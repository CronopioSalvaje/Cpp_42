#include "../Includes/PmergeMe.hpp"

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe(std::list<unsigned int> &lst): m_lst(lst)
{
    setVector();
    //printlist();
    //printvector();
}

PmergeMe::PmergeMe(PmergeMe const &cl)
{
}

PmergeMe::~PmergeMe()
{
}

void PmergeMe::operator=(PmergeMe const &cl)
{
}

template<typename T>
void swap(T *a, T *b)
{
    T temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

std::list<pair> PmergeMe::sliceList()
{
    std::list<pair> pairs;
    while (m_lst.size() > 1)
    {
        pair p;
        p.first = m_lst.back();
        m_lst.pop_back();
        p.second = m_lst.back();
        m_lst.pop_back();
        if (p.first < p.second)
            swap(&p.first, &p.second);
    }
    return pairs;
}

std::list<unsigned int> PmergeMe::sortList(std::list<unsigned int> toSort)
{
    std::list<unsigned int> sorted;
    std::list<pair> pairs;
    while (m_lst.size() > 1)
    {
        pair p;
        p.first = m_lst.back();
        m_lst.pop_back();
        p.second = m_lst.back();
        m_lst.pop_back();
        if (p.first < p.second)
            swap(&p.first, &p.second);
        pairs.push_back(p);
    }
    std::list<unsigned int> greaters, pendants;
    std::list<pair>::iterator it;
    for (it = pairs.begin(); it != pairs.end(); ++it)
    {
        greaters.push_front((*it).first);
        pendants.push_front((*it).second);
    }
    if (m_lst.size() % 2 != 0)
    {
        pendants.push_back(m_lst.back());
        m_lst.pop_back();
    }
    DEBUGGER("TOTO")
    printlist(greaters,"Greaters");
    printlist(pendants,"Pendants");
    return sorted;
}

void PmergeMe::sortList()
{
    std::list<pair> pairs = sliceList();
}




void PmergeMe::sortVector()
{}


void PmergeMe::sort(){
    sortList(m_lst);
    sortVector();
}

void PmergeMe::printlist()
{
    std::cout << "===PRINTLIST===" << std::endl;
    std::list<unsigned int>::iterator it;
    size_t count = 0;
    for (it = m_lst.begin(); it != m_lst.end(); ++it)
    {        
        std::cout << *it;
        if(count < m_lst.size() - 1)
            std::cout << " - ";
        count++;
    }
    std::cout << std::endl;

}

void PmergeMe::setVector()
{
    std::list<unsigned int>::iterator it;
    for (it = m_lst.begin(); it !=m_lst.end(); ++it)
    {
        m_vec.push_back(*it);
    }
}

void PmergeMe::printvector()
{
    std::cout << "===PRINTVECTOR===" << std::endl;
    std::vector<unsigned int>::iterator it;
    size_t count = 0;
    for (it = m_vec.begin(); it != m_vec.end(); ++it)
    {        
        std::cout << *it;
        if(count < m_vec.size() - 1)
            std::cout << " - ";
        count++;
    }
    std::cout << std::endl;
}
