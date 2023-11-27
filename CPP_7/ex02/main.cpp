#include "Array.hpp"

int main() {
    Array<std::string> a(3);
    Array<std::string> b(3);

    for (size_t i = 0; i < a.size(); i += 1) {
        std::cout << "a[" << i << "] = " << a[i] << "\n";
    }
    std::cout << std::endl;
    for (size_t i = 0; i < b.size(); i += 1) {
        std::cout << "b[" << i << "] = " << b[i] << "\n";
    }
    a[0] = "1";
    a[1] = "1";
    a[2] = "1";
    std::cout << std::endl;
    std::cout << "AFTER FILLING A WITH 1's" << std::endl;
    for (size_t i = 0; i < a.size(); i += 1) {
        std::cout << "a[" << i << "] = " << a[i] << "\n";
    }
    std::cout << std::endl;
    for (size_t i = 0; i < b.size(); i += 1) {
        std::cout << "b[" << i << "] = " << b[i] << "\n";
    }
    b = a;

    std::cout << "AFTER B = A" << std::endl;
    for (size_t i = 0; i < a.size(); i += 1) {
        std::cout << "a[" << i << "] = " << a[i] << "\n";
    }
    std::cout << std::endl;
    for (size_t i = 0; i < b.size(); i += 1) {
        std::cout << "b[" << i << "] = " << b[i] << "\n";
    }

    // Copy Constructor
    Array<std::string> copy(a);
    // Print
    std::cout << "Copy Constructor" << std::endl;
    for (size_t i = 0; i < copy.size(); i += 1) {
        std::cout << "copy[" << i << "] = " << copy[i] << "\n";
    }

    // Assignment Operator
    Array<std::string> assign;
    assign = a;
    // Print
    std::cout << "Assignment Operator" << std::endl;
    for (size_t i = 0; i < assign.size(); i += 1) {
        std::cout << "assign[" << i << "] = " << assign[i] << "\n";
    }

    // Print size of array
    std::cout << "Size of array: " << a.size() << std::endl;

    // Empty Array
    Array<std::string> empty;

    // Out of Bounds Exception
    try {
        std::cout << a[a.size() + 1] << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
