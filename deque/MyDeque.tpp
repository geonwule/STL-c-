template <typename T>
MyStack<T>::MyStack() : _size(0), _capacity(0), _arr(nullptr)
{
}

template <typename T>
MyStack<T>::MyStack(const MyStack &other) : _size(other._size), _capacity(other._capacity)
{
    if (!_capacity)
        _arr = nullptr;
    else
    {
        _arr = new T[_size];
        for (size_t i = 0; i < _size; i++)
        {
            _arr[i] = other._arr[i];
        }
    }
}

template <typename T>
MyStack<T>::~MyStack()
{
    if (_arr)
        delete[] _arr;
}

template <typename T>
bool MyStack<T>::empty() const
{
    return _size == 0;
}

template <typename T>
const size_t MyStack<T>::size() const
{
    return _size;
}

template <typename T>
const size_t MyStack<T>::capacity() const
{
    return _capacity;
}

template <typename T>
void MyStack<T>::push(const T& data)
{
    if (_size == _capacity) //할당된 배열이 꽉찼을 때
    {
        _capacity = _capacity == 0 ? 1 : _capacity * 2;
        T *new_arr = new T[_capacity];
        for (size_t i = 0; i < _size; i++) //copy
            new_arr[i] = _arr[i];

        delete[] _arr;
        _arr = new_arr;
    }
    _arr[_size++] = data;
}

template <typename T>
T& MyStack<T>::top() const
{
    if (empty())
        throw std::logic_error("Error: Out of bounds");
    return _arr[_size - 1];
}

template <typename T>
void MyStack<T>::pop()
{
    if (empty())
        throw std::logic_error("Error: Out of bounds");
    _size--;
}

// template <typename T>
// MyStack<T>::