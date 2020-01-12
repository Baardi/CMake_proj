#include <iostream>
#include "say-hello/hello.hpp"

void func()
{
    int a = 2;
    std::cout << a << std::endl;
}

int main()
{
    func();
    hello::say_hello();
    return 0;
}