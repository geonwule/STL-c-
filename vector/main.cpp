#include "MyVector.hpp"

#include <iostream>
#include <cstdlib>

void leaks()
{
    system("leaks MyVector");
}

#include <vector>
int main()
{
    // atexit(leaks); // leakcheck
    {
        std::cout << "==std::vector==\n";
        std::vector<int> sv(0);
        std::cout << "size = " << sv.size() << ", capacity = " << sv.capacity() << '\n';
        for (int i = 0; i < 10; i++)
        {
            sv.push_back(i);
            std::cout << "size = " << sv.size() << ", capacity = " << sv.capacity() << '\n';
        }
        std::cout << "==\\std::vector==\n";
    }

    {
        std::cout << "==MyVector==\n";
        MyVector<int> sv(0);
        std::cout << "size = " << sv.size() << ", capacity = " << sv.capacity() << '\n';
        for (int i = 0; i < 10; i++)
        {
            sv.push_back(i);
            std::cout << "size = " << sv.size() << ", capacity = " << sv.capacity() << '\n';
        }
        std::cout << "==\\MyVector==\n";
    }

    return 0;
}