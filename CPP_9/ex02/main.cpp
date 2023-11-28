#include "PmergeMe.hpp"

int main(int argc, char **argv) {
    if (argc <= 2) {
        std::cout << "Usage: ./a.out [numbers]" << std::endl;
        return -1;
    }
    PmergeMe<std::vector<int> > v; 
    PmergeMe<std::deque<int> > l;

    for (int i = 1; i < argc; i++) {
        std::vector<std::string> numbers = split(argv[i], ' ');
        for (std::vector<std::string>::const_iterator it = numbers.begin(); it != numbers.end(); ++it) {
            if (v.recognizeAndAddNumbers(*it) == -1) {
                std::cout << "Error" << std::endl;
                return -1;
            }
        }
    }
    for (int i = 1; i < argc; i++) {
        std::vector<std::string> numbers = split(argv[i], ' ');
        for (std::vector<std::string>::const_iterator it = numbers.begin(); it != numbers.end(); ++it) {
            if (l.recognizeAndAddNumbers(*it) == -1) {
                std::cout << "Error" << std::endl;
                return -1;
            }
        }
    }
    v.printAndSort("vector");
    l.printAndSort("deque");

    return 0;
}
