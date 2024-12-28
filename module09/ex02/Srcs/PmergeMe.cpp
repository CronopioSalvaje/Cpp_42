#include "../Includes/PmergeMe.hpp"

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe(std::vector<unsigned int> &vec): m_vec(vec)
{
    setList();
}

PmergeMe::PmergeMe(PmergeMe const &cl)
{
}

PmergeMe::~PmergeMe()
{
}

void PmergeMe::setList()
{
    std::vector<unsigned int>::iterator it;
    for (it = m_vec.begin(); it != m_vec.end(); ++it)
    {
        m_lst.push_back(*it);
    }
}

void PmergeMe::operator=(PmergeMe const &cl)
{
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
    //printlist(jacobsthal, "Jacobsthal suite");
    return jacobsthal;
}

unsigned int PmergeMe::getElementAtIndex(const std::list<unsigned int>& lst, size_t index)
{
    std::list<unsigned int>::const_iterator it = lst.begin();
    std::advance(it, index);
    return *it;
}

void PmergeMe::insertByBinaryLimitedResearch(pair p, std::vector<unsigned int> &lst)
{
    unsigned int right, left, mid;
    left = 0;
    if (p.first < lst.size())
        right = p.first;
    else
        right = lst.size() - 1;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (lst[mid] < p.second)
        {
            left = mid + 1;
        }
        else
            right = mid;
    }
    lst.insert(lst.begin() + left, p.second);
}

void PmergeMe::insertByBinaryLimitedResearchList(pair p, std::list<unsigned int> &lst)
{
    unsigned int right, left, mid;
    left = 0;
    if (p.first < lst.size())
        right = p.first;
    else
        right = lst.size() - 1;
    while (left < right)
    {
        int mid = left + (right - left) / 2;
        if (getElementAtIndex(lst, mid) < p.second)
            left = mid + 1;
        else
            right = mid;
    }
    std::list<unsigned int>::iterator it = lst.begin();
    std::advance(it, left);
    lst.insert(it, p.second);
}

void PmergeMe::insertByBinaryResearchList(std::list<unsigned int> &lst, std::list<unsigned int> &alone)
{
    unsigned int right, left, mid;
    left = 0;
    right = lst.size();
  
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (getElementAtIndex(lst, mid) < alone.back())
            left = mid + 1;
        else
            right = mid;
    }
    std::list<unsigned int>::iterator it = lst.begin();
    std::advance(it, left);
    lst.insert(it, alone.back());
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
        insertByBinaryLimitedResearch(pairs[*it - 1], lst);
    } 
    return lst;
}

std::list<unsigned int> PmergeMe::sortPendantsList(std::list<unsigned int> &lst, std::vector<pair> pairs)
{
    std::vector<size_t> jacobsthalSuite = getJacobsthalSuite(pairs.size());
    std::vector<size_t>::iterator it;
    
    for (it = jacobsthalSuite.begin(); it != jacobsthalSuite.end(); ++it)
    {
        insertByBinaryLimitedResearchList(pairs[*it - 1], lst);
    } 
    return lst;
}



std::vector<unsigned int> PmergeMe::sortVector(std::vector<unsigned int> lst)
{
    static size_t loop = 1;
    std::vector<unsigned int> sorted;
    std::vector<unsigned int> greaters, alone;
    std::vector<pair> pairs = sliceList(lst);
    if (lst.size() == 1)
    {
        alone.push_back(lst.back());
        lst.pop_back();
    }
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
    }
    if (pairs.size() > 1) 
    {
        std::vector<pair>::reverse_iterator it;
        for (it = pairs.rbegin(); it != pairs.rend(); ++it)
            greaters.push_back((*it).first); 
        if (!isSortedList(greaters))
        {
            sorted = sortVector(greaters);
        }
        else
            sorted = greaters;
        sorted = sortPendants(sorted, pairs);
    }    
    if (alone.size() > 0 )
        insertByBinaryResearch(sorted, alone);
    return sorted;
}

std::list<unsigned int> PmergeMe::sortList(std::list<unsigned int> lst)
{
    std::list<unsigned int> sorted;
    std::list<unsigned int> greaters, alone;
    std::vector<pair> pairs = sliceList(lst);
    if (lst.size() % 2 != 0)
    {
        alone.push_back(lst.back());
        lst.pop_back();
    }
    if (pairs.size() == 1)
    {
        std::vector<pair>::iterator it = pairs.begin();
        if (it->first > it->second)        
        {
            sorted.push_back(it->second);
            sorted.push_back(it->first);
        }else
        {
            sorted.push_back(it->first);
            sorted.push_back(it->second);
        }    
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
        sorted = sortPendantsList(sorted, pairs);
    }
    if (alone.size() > 0 )
        insertByBinaryResearchList(sorted, alone);
    return sorted;
}

void PmergeMe::sort(){
    
    printlist(m_vec, "std::vector before : ");
    clock_t start_vec = clock();
    m_vec = sortVector(m_vec);
    printlist(m_vec, "std::vector after : ");
    clock_t stop_vec = clock();

    clock_t start_lst = clock();
    printlist(m_lst, "std::list before : ");
    m_lst = sortList(m_lst);
    printlist(m_lst, "std::list after : ");
    clock_t stop_lst = clock();
    

    double velapsedTime_us = (static_cast<double>(stop_vec - start_vec));
    double velapsedTime_s = (static_cast<double>(stop_vec - start_vec)/CLOCKS_PER_SEC);
    double lelapsedTime_us = (static_cast<double>(stop_lst - start_lst));
    double lelapsedTime_s = (static_cast<double>(stop_lst - start_lst)/CLOCKS_PER_SEC);
    std::string vCOLOR, lCOLOR;
    if (velapsedTime_s > lelapsedTime_s)
    {
        vCOLOR = RED;
        lCOLOR = BOLD_GREEN;        
    }else if (velapsedTime_s == lelapsedTime_s)
    {
        vCOLOR = BOLD_BLUE;
        lCOLOR = BOLD_BLUE; 
    }else
     {
        vCOLOR = BOLD_GREEN;
        lCOLOR = RED; 
    }
    
    std::cout << "Time to process a range of " << BLUE << m_vec.size() << RESET << " elements with std::vector<size_t> : " << vCOLOR << velapsedTime_us << RESET <<" us - " <<  vCOLOR << velapsedTime_s << RESET << " s" << std::endl;
    std::cout << "Time to process a range of " << BLUE << m_lst.size() << RESET << " elements with std::list<size_t> : " << lCOLOR << lelapsedTime_us << RESET " us - " << lCOLOR << lelapsedTime_s << RESET << " s" << std::endl;

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
            std::cout << " ";
        count++;
    }
    std::cout << std::endl;
}
