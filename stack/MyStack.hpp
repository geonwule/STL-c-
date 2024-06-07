#ifndef MYSTACK_HPP
#define MYSTACK_HPP

#include <cstddef> //size_t
#include <stdexcept> //logic_error

template <typename T>
class MyStack
{

private:
    T *_arr;
    size_t _size; //실제 요소의 개수
    size_t _capacity; //배열의 크기

public:
    MyStack();
    MyStack(const MyStack& other);
    ~MyStack();

    bool empty() const;
    const size_t size() const;
    const size_t capacity() const;

    void push(const T& data);
    T& top() const;
    void pop();
};

#include "MyStack.tpp"

#endif