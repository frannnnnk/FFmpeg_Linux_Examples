#include <iostream>
#include "stdlib.h"

void processValue(int & value)
{
    std::cout << ">>> Lvalue: " << value << std::endl;
    value = 42;
}

void processValue(int && value)
{
    std::cout << ">>> Rvalue: " << value << std::endl;
}

template<typename T>
void forwardValue(T && value) 
{
    processValue(std::forward<T>(value));
}

int main() 
{
    int x = 10;
    forwardValue(x);
    std::cout << ">>> After forwarding, x=" << x << std::endl;  
    
    forwardValue(20);
    return EXIT_SUCCESS;
}