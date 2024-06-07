# 📌 stack
std::stack을 직접 구현해보았습니다.
<br/>
<br/>

# 🏗️ Architecture

```c++
// vector와 비슷하게 구현해본 버전
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
```

<br/>
<br/>

# :memo: reference
[![Techblog](https://img.shields.io/badge/reference-00599C?style=for-the-badge&logo=cplusplus&logoColor=white)](https://en.cppreference.com/w/cpp/container/stack)


<!-- makedown preview : cmd + shift + v -->
<!--
https://www.d5br5.dev/blog/pro_tip/tech_stack_icon  // 기술스택 뱃지 활용법 블로그
https://simpleicons.org/ // 뱃지 홈페이지
<img src="https://img.shields.io/badge/C/<Name>-<Color>?style=for-the-badge&logo=<TechName>&logoColor=white"/><a> // 기술스택 뱃지 양식
-->
