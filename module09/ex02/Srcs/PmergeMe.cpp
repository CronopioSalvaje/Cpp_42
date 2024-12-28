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

std::vector<size_t> PmergeMe::getJacobsthalSuite(size_t size)
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
        //std::cout << "- i:" << i << " - " << jnumb << std::endl;
        jacobsthal.push_back(jnumb);
        i++;
    }
    // add complement or find a way to manage it?
    std::vector<size_t>::iterator it = jacobsthal.begin();
    for (i = 1; i <= size; ++i)
    {
        if (std::find(jacobsthal.begin(), jacobsthal.end(), i) == jacobsthal.end())
        {
            jacobsthal.push_back(i);
            //std::cout << "- i:" << i << " - " << i << std::endl;
        }
    }
    jacobsthal.erase(std::find(jacobsthal.begin(), jacobsthal.end(),0));
    jacobsthal.erase(std::find(jacobsthal.begin(), jacobsthal.end(),1));
    printlist(jacobsthal, "Jacobsthal suite");
    return jacobsthal;
}

void PmergeMe::insertByBinaryLimitedResearch(pair p, std::vector<unsigned int> &lst)
{
    unsigned int right, left, mid;
    left = 0;
    if (p.first < lst.size())
        right = p.first;
    else
        right = lst.size() - 1;

    printlist(lst, "LIST");
    std::cout << "to insert : " << p.second << std::endl;
    while (left < right) {
        int mid = left + (right - left) / 2;
        std::cout << "current val : " << lst[mid] << "  -  to insert : " << p.second << std::endl;
        if (lst[mid] < p.second)
        {
            left = mid + 1;
        } /////////////////////////////////break here
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

std::vector<unsigned int> PmergeMe::sortPendants(std::vector<unsigned int> &lst, std::vector<pair> pairs)
{ 
    std::vector<size_t> jacobsthalSuite = getJacobsthalSuite(pairs.size());
    std::vector<size_t>::iterator it;
    
    for (it = jacobsthalSuite.begin(); it != jacobsthalSuite.end(); ++it)
    {
        std::cout << "jacobsthal index : " << *it << std::endl;
        insertByBinaryLimitedResearch(pairs[*it - 1], lst);
    } 
    return lst;
}

std::vector<unsigned int> PmergeMe::sortList(std::vector<unsigned int> lst)
{
    DEBUGGER(1)
    std::vector<unsigned int> sorted;
    std::vector<unsigned int> greaters, alone;
    printlist(lst, "received");
    std::vector<pair> pairs = sliceList(lst);
    if (lst.size() % 2 != 0)
    {
        alone.push_back(lst.back());
        lst.pop_back();
    }
    std::cout << "first : " << pairs[0].first << " - second : " << pairs[0].second << std::endl;
    if (pairs.size() == 1)
    {
        if (pairs[0].first > pairs[0].second)
        {
            sorted.push_back(pairs[0].second);
            sorted.push_back(pairs[0].first);
        }else
        {
            sorted.push_back(pairs[0].first);
            sorted.push_back(pairs[0].second);
        }
        printlist(sorted, "LAST");
    }

    if (pairs.size() > 1) 
    {
        std::vector<pair>::reverse_iterator it;
        for (it = pairs.rbegin(); it != pairs.rend(); ++it)
            greaters.push_back((*it).first); 
        if (!isSortedList(greaters))
        {
            sorted = sortList(greaters);
        }
        sorted = sortPendants(greaters, pairs);
    }    
    if (alone.size() > 0 )
        insertByBinaryResearch(sorted, alone);
    return sorted;
}

void PmergeMe::sortList()
{

}




void PmergeMe::sortVector()
{}


void PmergeMe::sort(){
    m_vec = sortList(m_vec);
    
    printlist(m_vec, "Sorted");
    //printlist(sortList(m_lst),"SORTED");
    //sortVector();
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
