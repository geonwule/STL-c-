#include "MyStack.hpp"

#include <iostream>
#include <cstdlib>

void leaks()
{
    system("leaks MyStack");
}

#include <stack>

int main()
{
    // atexit(leaks); // leakcheck
    {
        try
        {
            std::cout << "==std::stack==\n";
            std::stack<int> sv;
            // sv.pop();
            // std::cout << "size = " << sv.size() << ", top = " << sv.top() << '\n';
            for (int i = 0; i < 10; i++)
            {
                sv.push(i);
                std::cout << "size = " << sv.size() << ", top = " << sv.top() << '\n';
                sv.pop();
            }
            std::cout << "==\\std::stack==\n";
        }
        catch (std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }
    }

    {
        try
        {
            std::cout << "==MyStack==\n";
            MyStack<int> sv;
            // std::cout << "size = " << sv.size() << ", top = " << sv.top() << '\n';
            for (int i = 0; i < 10; i++)
            {
                sv.push(i);
                // if (i % 2 == 1)
                    // sv.pop();
                std::cout << "size = " << sv.size() << ", capacity = " << sv.capacity() << " top = " << sv.top() << '\n';
            }
            std::cout << "==\\MyStack==\n";
        }
        catch (std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }
    }

    return 0;
}