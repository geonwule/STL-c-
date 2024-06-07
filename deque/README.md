# 📌 deque
std::deque을 직접 구현해보았습니다.
<br/>
<br/>

# 🏗️ Architecture

```c++
//claude
#include <iostream>
#include <cstdlib>

template <typename T>
class Deque {
private:
    static const size_t CHUNK_SIZE = 16; // 청크 크기
    T** chunks; // 청크 포인터 배열
    size_t num_chunks; // 청크 개수
    size_t front_idx; // 첫 번째 요소의 인덱스
    size_t back_idx; // 마지막 요소의 인덱스 + 1
    size_t size; // 요소 개수

public:
    Deque() : chunks(nullptr), num_chunks(0), front_idx(0), back_idx(0), size(0) {}

    ~Deque() {
        clear();
        delete[] chunks;
    }

    void push_back(const T& value) {
        if (back_idx == (num_chunks * CHUNK_SIZE)) {
            grow_back();
        }
        chunks[back_idx / CHUNK_SIZE][back_idx % CHUNK_SIZE] = value;
        back_idx++;
        size++;
    }

    void push_front(const T& value) {
        if (front_idx == 0) {
            grow_front();
        }
        front_idx--;
        chunks[front_idx / CHUNK_SIZE][front_idx % CHUNK_SIZE] = value;
        size++;
    }

    void pop_back() {
        if (empty()) {
            std::cout << "Deque is empty!" << std::endl;
            return;
        }
        back_idx--;
        size--;
    }

    void pop_front() {
        if (empty()) {
            std::cout << "Deque is empty!" << std::endl;
            return;
        }
        front_idx++;
        size--;
    }

    T& front() {
        if (empty()) {
            std::cout << "Deque is empty!" << std::endl;
            throw std::runtime_error("Attempted to access front of an empty deque");
        }
        return chunks[front_idx / CHUNK_SIZE][front_idx % CHUNK_SIZE];
    }

    T& back() {
        if (empty()) {
            std::cout << "Deque is empty!" << std::endl;
            throw std::runtime_error("Attempted to access back of an empty deque");
        }
        return chunks[back_idx / CHUNK_SIZE][back_idx % CHUNK_SIZE - 1];
    }

    bool empty() const {
        return size == 0;
    }

    size_t get_size() const {
        return size;
    }

private:
    void grow_back() {
        T** new_chunks = new T*[num_chunks + 1];
        for (size_t i = 0; i < num_chunks; i++) {
            new_chunks[i] = chunks[i];
        }
        new_chunks[num_chunks] = new T[CHUNK_SIZE];
        delete[] chunks;
        chunks = new_chunks;
        num_chunks++;
    }

    void grow_front() {
        T** new_chunks = new T*[num_chunks + 1];
        for (size_t i = 0; i < num_chunks; i++) {
            new_chunks[i + 1] = chunks[i];
        }
        new_chunks[0] = new T[CHUNK_SIZE];
        front_idx += CHUNK_SIZE;
        delete[] chunks;
        chunks = new_chunks;
        num_chunks++;
    }

    void clear() {
        for (size_t i = 0; i < num_chunks; i++) {
            delete[] chunks[i];
        }
        num_chunks = 0;
        front_idx = 0;
        back_idx = 0;
        size = 0;
    }
};
```

<br/>
<br/>

# :memo: reference
[![Techblog](https://img.shields.io/badge/reference-00599C?style=for-the-badge&logo=cplusplus&logoColor=white)](https://en.cppreference.com/w/cpp/container/deque)


<!-- makedown preview : cmd + shift + v -->
<!--
https://www.d5br5.dev/blog/pro_tip/tech_deque_icon  // 기술스택 뱃지 활용법 블로그
https://simpleicons.org/ // 뱃지 홈페이지
<img src="https://img.shields.io/badge/C/<Name>-<Color>?style=for-the-badge&logo=<TechName>&logoColor=white"/><a> // 기술스택 뱃지 양식
-->
