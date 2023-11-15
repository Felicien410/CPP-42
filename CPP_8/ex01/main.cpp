#include "Span.hpp"

int main()
{ 
    Span sp= Span(10);
    sp.addNumber(6);
    sp.addNumbers(10, 15);
    sp.addNumber(3);

    sp.printElements();

    std::cout<<sp.shortestSpan()<<std::endl;
    std::cout<<sp.longestSpan()<<std::endl;

    std::cout<<std::endl;
    std::cout<<"Test with same value :"<<std::endl;
    try {
        sp.addNumber(3);
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }
    try {
        sp.addNumbers(10, 11);
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout<<std::endl;
    std::cout << "Test with empty tab :"<<std::endl;
    Span sp2 = Span(1);
    try {
        std::cout<<sp2.longestSpan()<<std::endl;
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }

    try {
        std::cout<<sp2.shortestSpan()<<std::endl;
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout<<std::endl;
    std::cout << "Test with one element :"<<std::endl;
    Span sp3 = Span(1);
    sp3.addNumber(1);
    try {
        std::cout<<sp3.longestSpan()<<std::endl;
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout<<std::endl;
    std::cout << "Test with range inversed :"<<std::endl;
    Span sp4 = Span(10);
    sp4.addNumbers(15, 10);
    sp4.printElements();
    std::cout<<sp4.shortestSpan()<<std::endl;
    std::cout<<sp4.longestSpan()<<std::endl;

    std::cout<<std::endl;
    std::cout << "test with high number :"<<std::endl;
    Span sp5 = Span(100);
    sp5.addNumbers(0, 99);
    sp5.printElements();
    std::cout<<sp5.shortestSpan()<<std::endl;
    std::cout<<sp5.longestSpan()<<std::endl;
    return 0;
}