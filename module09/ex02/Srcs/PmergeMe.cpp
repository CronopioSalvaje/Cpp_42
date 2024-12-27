#include "../Includes/PmergeMe.hpp"

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe(std::vector<unsigned int> &lst): m_lst(lst)
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

std::vector<pair> PmergeMe::sliceList(std::vector<unsigned int> &lst)
{
    std::vector<pair> pairs;
    size_t limit = 0;
    if (m_lst.size() % 2 != 0)
        limit = 1;
    while (m_lst.size() > limit)
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
    return pairs;
}

std::vector<size_t> PmergeMe::getJacobshtalSuite(size_t size)
{
    std::vector<size_t> jacobsthal;
    jacobsthal.push_back(0);
    jacobsthal.push_back(1);
    size_t i = 2;
    size_t s = size;
    while (s--)
    {
        size_t jnumb = jacobsthal[i-1] + 2 * jacobsthal[i - 2];
        if (jnumb > size)
            break;
        std::cout << "- i:" << i << " - " << jnumb << std::endl;
        jacobsthal.push_back(jnumb);
        i++;
    }
    // add complement or find a way to manage it?
    return jacobsthal;
}

void PmergeMe::insertByBinaryLimitedResearch(pair p, std::vector<unsigned int> &lst)
{
    DEBUGGER(410)
    unsigned int right, left, mid;
    left = 0;
    right = p.first;
    DEBUGGER(411)
    DEBUGGER(p.first)
      
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (lst[mid] < p.second)
            left = mid + 1;
        else
            right = mid;
    }
    lst.insert(lst.begin() + left, p.second);
}

void PmergeMe::insertByBinaryResearch(std::vector<unsigned int> &lst, std::vector<unsigned int> &alone)
{
    unsigned int right, left, mid;
    left = 0;
    right = lst.size();
  
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (lst[mid] < alone.back())
            left = mid + 1;
        else
            right = mid;
    }
    lst.insert(lst.begin() + left, alone.back());
}

std::vector<unsigned int> PmergeMe::sortPendants(std::vector<unsigned int> lst, std::vector<pair> pairs, std::vector<unsigned int> alone)
{
    getJacobshtalSuite(pairs.size());
    std::vector<pair>::iterator p_it = pairs.begin();
    std::vector<pair>::iterator p_it2 = pairs.begin();
    p_it2++;
    for (p_it; p_it != pairs.end();)
    {
        insertByBinaryLimitedResearch(*p_it, lst);
        p_it++;
        if (p_it != pairs.end())
            p_it++;
    }
    DEBUGGER(4)
    if (pairs.size() > 1)
    {
        for (p_it2; p_it2 != pairs.end();)
        {
            DEBUGGER(40)
            insertByBinaryLimitedResearch(*p_it2, lst);
            DEBUGGER(41)
            p_it2++;
            if (p_it2 != pairs.end())
                p_it2++;
        }
    }
    if (alone.size() >0 )
        insertByBinaryResearch(alone, lst);
    DEBUGGER(5)
    return lst;
}

std::vector<unsigned int> PmergeMe::sortList(std::vector<unsigned int> lst)
{
    DEBUGGER(1)
    std::vector<unsigned int> sorted;
    std::vector<pair> pairs = sliceList(lst);
    // faire procedure si pair == 1 et 0;
    DEBUGGER("SIZE : ")
    DEBUGGER(pairs.size())
    getJacobshtalSuite(pairs.size());
    DEBUGGER("END")
    std::vector<unsigned int> greaters, alone;
    std::vector<pair>::iterator it;
    for (it = pairs.begin(); it != pairs.end(); ++it)
        greaters.push_back((*it).first);
    if (lst.size() % 2 != 0)
    {
        alone.push_back(lst.back());
        lst.pop_back();
    }
    DEBUGGER(2)
    if (!isSortedList(greaters))
        sortList(greaters);
    DEBUGGER(3)
    sorted = sortPendants(greaters, pairs, alone);
    DEBUGGER(4)
    printlist(greaters,"GREATERS");
    printlist(sorted,"SORTED");
    return sorted;
}

void PmergeMe::sortList()
{

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
    std::vector<unsigned int>::iterator it;
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
    std::vector<unsigned int>::iterator it;
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
