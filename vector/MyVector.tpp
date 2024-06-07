template <typename T>
MyVector<T>::MyVector() : _size(0), _capacity(0), _arr(nullptr)
{
}

template <typename T>
MyVector<T>::MyVector(size_t size) : _size(size), _capacity(size)
{
    if (!_capacity)
        _arr = nullptr;
    _arr = new T[_capacity];
}

template <typename T>
MyVector<T>::MyVector(size_t size, const T data) : _size(size), _capacity(size)
{
    _arr = new T[_capacity];
    for (auto &e : _arr)
        e = data;
}

template <typename T>
MyVector<T>::MyVector(const MyVector &other) : _size(other._size), _capacity(other._capacity)
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
MyVector<T>::~MyVector()
{
    if (_arr)
        delete[] _arr;
}

template <typename T>
const size_t MyVector<T>::size() const
{
    return _size;
}

template <typename T>
const size_t MyVector<T>::capacity() const
{
    return _capacity;
}

template <typename T>
void MyVector<T>::push_back(const T& data)
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
T& MyVector<T>::operator[](size_t idx) const
{
    if (idx >= _size)
        throw std::logic_error("Out of bounds");
    
    return _arr[idx];
}

// template <typename T>
// MyVector<T>::