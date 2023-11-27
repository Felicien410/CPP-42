#include "Span.hpp"

int main(void) {
    //make a main that test all posssibilities
    Span sp = Span(5);
    sp.addNumber(5);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    sp.printElements();
    std::cout << "shortest span: " << sp.shortestSpan() << std::endl;
    std::cout << "longest span: " << sp.longestSpan() << std::endl;
    std::cout << std::endl;
    std::cout << "add over max size: " << std::endl;
    try {
        sp.addNumber(42);
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << std::endl;
    std::cout << "add range: " << std::endl;
    std::vector<int> tab;
    Span sp2 = Span(10);
    tab.push_back(1);
    tab.push_back(2);
    tab.push_back(3);
    tab.push_back(4);
    tab.push_back(5);
    tab.push_back(6);
    tab.push_back(7);
    tab.push_back(8);
    tab.push_back(9);
    tab.push_back(20);
    try {
        sp2.addNumbers(tab.begin(), tab.end());
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    sp2.printElements();
    std::cout << "shortest span: " << sp2.shortestSpan() << std::endl;
    std::cout << "longest span: " << sp2.longestSpan() << std::endl;
    std::cout << std::endl;
    std::cout << "add range over max size: " << std::endl;
    try {
        sp2.addNumber(1);
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << std::endl;
    std::cout << "add range: " << std::endl;
    Span sp3 = Span(10);
    try {
        sp3.addRange(1, 10);
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    sp3.printElements();
    std::cout << "shortest span: " << sp3.shortestSpan() << std::endl;
    std::cout << "longest span: " << sp3.longestSpan() << std::endl;
    std::cout << std::endl;


    std::cout << std::endl;
    std::cout << "no span: " << std::endl;
    Span sp4 = Span(0);
    try {
        sp4.addNumber(1);
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << std::endl;

    //test with 1 elements
    std::cout << "test with 1 elements: " << std::endl;
    Span sp6 = Span(2);
    sp6.addNumber(1);
    try {
        std::cout << "shortest span: " << sp6.shortestSpan() << std::endl;
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << std::endl;

    //test with 10000 elements
    std::cout << "test with 10000 elements: " << std::endl;
    Span sp5 = Span(10000);
    sp5.addRange(1, 10000);
    std::cout << "shortest span: " << sp5.shortestSpan() << std::endl;
    std::cout << "longest span: " << sp5.longestSpan() << std::endl;
    std::cout << std::endl;

}