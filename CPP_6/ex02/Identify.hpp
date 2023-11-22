#ifndef IDENTIFY_HPP
#define IDENTIFY_HPP

#include <stdlib.h>
#include <iostream>
#include <string>

class Base
{
    public:
        virtual ~Base() {};
};

class A : public Base
{
};

class B : public Base
{
};

class C : public Base
{
};

#endif

