#include <iostream>
#include <say-hello/hello.hpp>
#include <ranges>
#include <vector>
#include <algorithm>

void func()
{
    int a = 3;
    std::cout << a << " This is democracy manifest" << std::endl;
}

template <class T>
std::ostream& operator<<(std::ostream& os, const std::vector<T> &vec)
{
    os << "{";
    for (auto it = vec.begin(); it != vec.end(); ++it)
    {
        os << *it;
        if (it != --vec.end())
           os << ", "; 
    }
    return  os << "}";
}

int main()
{
#ifdef __MINGW64__ 
    std::cout << "x64" << std::endl;
#endif

    std::vector<int> v{1, 3, 4, 5};
    auto it = std::ranges::find(v, 4);
    v.erase(it);
    
    [&](){
        std::cout << "this is cpp-version" << __cplusplus << std::endl;
        std::cout << "this is " << v << " manifest!" << std::endl;
    }();
    
    func();
    hello::say_hello();
    return 0;
}