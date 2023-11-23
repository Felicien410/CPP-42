#ifndef SERIALIZATION_HPP
# define SERIALIZATION_HPP

#include <iostream>
#include <string>
#include <stdlib.h>

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

    static unsigned long serialize(Data* ptr);
    static Data* deserialize(unsigned long raw);
};

#endif
