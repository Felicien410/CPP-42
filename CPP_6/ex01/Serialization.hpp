#include <iostream>
#include <string>
#include <stdlib.h>

#ifndef SERIALIZATION_HPP
# define SERIALIZATION_HPP

struct Data
{
    std::string s1;
    int n;
    std::string s2;
};

//static class
class Serialization
{
public:
    //static function
    Serialization();
    Serialization(const Serialization & src);
    ~Serialization();
    Serialization & operator=(const Serialization & rhs);

    uintptr_t serialize(Data* ptr);
    Data* deserialize(uintptr_t raw);
};

#endif
