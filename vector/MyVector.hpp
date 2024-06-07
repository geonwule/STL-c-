#ifndef MYVECTOR_HPP
#define MYVECTOR_HPP

#include <cstddef> //size_t
#include <stdexcept> //logic_error

template <typename T>
class MyVector
{

private:
    T *_arr;
    size_t _size; //실제 요소의 개수
    size_t _capacity; //배열의 크기

public:
    MyVector();
    MyVector(size_t size);
    MyVector(size_t size, const T data);
    MyVector(const MyVector& other);
    ~MyVector();

    const size_t size() const;
    const size_t capacity() const;

    void push_back(const T& data);
    T& operator[](size_t idx) const;
};

#include "MyVector.tpp"

#endif