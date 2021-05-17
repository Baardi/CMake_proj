#include <iostream>
#include <say-hello/hello.hpp>
#include <ranges>
#include <vector>
#include <algorithm>
#include "MyClass.hpp"
#include <memory>
#include <set>

void func()
{
    int a = 3;
    std::cout << a << " This is democracy manifest" << std::endl;
}

int main()
{
#ifdef __MINGW64__ 
    std::cout << "x64" << std::endl;
#endif    
    {

        //std::cout << *myNode << std::endl;
    }

    MyClass m;
    m.MyMethod();

    std::set<int> v{1, 3, 4, 5};
    
    auto it2 = v.find(5);
    auto it3 = std::find(v.begin(), v.end(), 5);

    auto it = std::ranges::find(v, 4);
    
    v.erase(it);
    
    [&](){
        std::cout << "this is cpp-version " << __cplusplus << std::endl;
        //std::cout << "this is " << v << " manifest!" << std::endl;
    }();
    
    func();
    hello::say_hello();
    return 0;
}