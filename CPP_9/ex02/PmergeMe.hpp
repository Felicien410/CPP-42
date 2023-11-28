#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <string>
#include <cstdlib> 
#include <climits>
#include <iostream>
#include <algorithm>
#include <ctime> 
#include <deque>
#include <sstream>

template<typename Container>
class PmergeMe {
    public:
        PmergeMe();
        ~PmergeMe();    
        PmergeMe(PmergeMe const & src);
        PmergeMe & operator=(PmergeMe const & rhs);

        int recognizeAndAddNumbers(std::string argv);
        void addNumber(int n);
        void printSequence();
        void sortPairs();
        void putMinInNewContainer();
        void printMinSequence();
        void mergeInsertSort();
        void printAndSort(std::string type_name);

    private:
        Container _sequence;
        Container _minSequence;
};

template<typename Container>
PmergeMe<Container>::PmergeMe() {}

template<typename Container>
PmergeMe<Container>::~PmergeMe() {}

template<typename Container>
PmergeMe<Container>::PmergeMe(const PmergeMe& cpy) {
    *this = cpy;
}

template<typename Container>
PmergeMe<Container> &PmergeMe<Container>::operator=(const PmergeMe& rhs) {
    if (this != &rhs) {
        _sequence = rhs._sequence;
        _minSequence = rhs._minSequence;
    }
    return *this;
}

template<typename Container>
int PmergeMe<Container>::recognizeAndAddNumbers(std::string argv) {
    for(unsigned int i = 0; i < argv.size() ; i++)
    {
        if ( !isdigit(argv[i])) 
        {
            return -1;
        }
    }
    long int n = strtol(argv.c_str(), NULL, 10);
    if (n > INT_MAX || n < INT_MIN)
        return -1;
    else
    {
        for (typename Container::const_iterator it = _sequence.begin(); it != _sequence.end(); ++it)
        {
            if (*it == n)
            {
                //std::cout << "Doublon" << std::endl;
                return(1);
            }
        }
        addNumber(n);
        return 0;
    }
}

template<typename Container>
void PmergeMe<Container>::addNumber(int n) {
    _sequence.push_back(n);
}

template<typename Container>
void PmergeMe<Container>::printSequence() {
    for (typename Container::const_iterator it = _sequence.begin(); it != _sequence.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

// Trier les paires
template<typename Container>
void PmergeMe<Container>::sortPairs() {
    for (typename Container::iterator it = _sequence.begin(); 
         it != _sequence.end() && it + 1 != _sequence.end(); it += 2) {
        if (*it > *(it + 1)) {
            std::iter_swap(it, it + 1);
        }
    }
}

template<typename Container>
void PmergeMe<Container>::putMinInNewContainer() {
    for (typename Container::iterator it = _sequence.begin(); it != _sequence.end();) {
        typename Container::iterator it_next = it;
        it_next++;
        if (it_next == _sequence.end()) {
            _minSequence.push_back(*it);
            it = _sequence.erase(it);
            continue;
        }
        if (*it < *it_next) {
            _minSequence.push_back(*it);
            it = _sequence.erase(it);
        } else {
            _minSequence.push_back(*it_next);
            it = _sequence.erase(it_next);
        }
    }
}

template<typename Container>
void PmergeMe<Container>::printMinSequence() {
    for (typename Container::const_iterator it = _minSequence.begin(); it != _minSequence.end(); ++it) {
        std::cout << "[" << *it << "] ";
    }
    std::cout << std::endl;
}

template<typename Container>
void PmergeMe<Container>::mergeInsertSort() {
    std::sort(_minSequence.begin(), _minSequence.end());
    std::sort(_sequence.begin(), _sequence.end());
    
    Container tmp;
    std::merge(_minSequence.begin(), _minSequence.end(), _sequence.begin(), _sequence.end(), std::back_inserter(tmp));
    _sequence = tmp;
}

template<typename Container>
void PmergeMe<Container>::printAndSort(std::string type_name) {
    std::cout << "Before:\t";
    printSequence();

    std::clock_t start = std::clock();

    sortPairs();
    putMinInNewContainer();
    mergeInsertSort();

    std::clock_t end = std::clock();
    double elapsed_time = double(end - start) / CLOCKS_PER_SEC * 1000000; 

    std::cout << "After:\t";
    printSequence();

    std::cout << "Time to process a range of " << _sequence.size() 
              << " elements: " << elapsed_time << "us " << "with std::" 
                << type_name << std::endl;
    std::cout << std::endl;
}

std::vector<std::string> split(const std::string &str, char delim);

#endif
