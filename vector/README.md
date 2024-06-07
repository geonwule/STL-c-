# 📌 vector
std::vector를 직접 구현해보았습니다.
<br/>
<br/>

# 🏗️ Architecture

```c++
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
```

<br/>
<br/>

# :memo: reference
[![Techblog](https://img.shields.io/badge/reference-00599C?style=for-the-badge&logo=cplusplus&logoColor=white)](https://en.cppreference.com/w/cpp/container/vector)


<!-- makedown preview : cmd + shift + v -->
<!--
https://www.d5br5.dev/blog/pro_tip/tech_stack_icon  // 기술스택 뱃지 활용법 블로그
https://simpleicons.org/ // 뱃지 홈페이지
<img src="https://img.shields.io/badge/C/<Name>-<Color>?style=for-the-badge&logo=<TechName>&logoColor=white"/><a> // 기술스택 뱃지 양식
-->
