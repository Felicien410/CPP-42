#ifndef ARRAY_HPP
# define ARRAY_HPP
#include <iostream>
#include <string>


template <class T> class Array
{
    private:
        unsigned int _size;
        T *_array;
    public:
        Array();
        Array(unsigned int n);
        Array(Array const &src);
        ~Array();
        Array &operator=(Array const &src);
        T operator[](unsigned int i) const;
        T&  operator[](unsigned int i);
        T getData(unsigned int i) const;
        unsigned int size() const;
};

template<typename T>
Array<T>::Array()
{
    this->_array = new T[0];
    this->_size = 0;
    return;
}

template<typename T>
Array<T>::Array(unsigned int n)
{
    this->_array = new T[n];
    this->_size = n;
    return;
}

template<typename T>
Array<T>::Array(Array const &src)
{
    if (this != &src)
    {
        this->_array = new T[src._size];
        this->_size = src._size;
        for (unsigned int i = 0; i < src._size; i++)
            this->_array[i] = src._array[i];
    }
}

template<typename T>
Array<T>::~Array()
{
    delete [] this->_array;
    return;
}

template<typename T>
Array<T>& Array<T>::operator=(Array const &src)
{
    if (this != &src)
    {
        delete[] this->_array;
        this->_array = new T[src._size];
        this->_size = src._size;
        for (unsigned int i = 0; i < src._size; i++)
            this->_array[i] = src._array[i];
    }
    return *this;
}

template<typename T>
T Array<T>::operator[](unsigned int i) const
{
    if (i < 0 || i >= this->_size)
        throw std::exception();
    return getData(i);
}

template<typename T>
T Array<T>::getData(unsigned int i) const
{
    if (i < 0 || i >= this->_size)
        throw std::exception();
    return this->_array[i];
}

template<typename T>
T& Array<T>::operator[](unsigned int i)
{
    if (i >= this->_size)
        throw std::exception();
    return this->_array[i];
}

template<typename T>
unsigned int Array<T>::size() const
{
    return this->_size;
}

#endif