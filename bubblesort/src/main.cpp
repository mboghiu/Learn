#include <iostream>
#include <vector>
#include <algorithm>
#include <complex>
#include <cassert>


template<typename T>
void AreEqual(const std::vector<T>& expected, const std::vector<T> actual)
{
    if (expected == actual)
        std::cout << "\033[32mPASS\033[0m" << std::endl;
    else
    {
        std::cout << "\033[31mFAIL\033[0m" << std::endl;
        std::cout << "expected: ";
        for (auto& v : expected)
            std::cout << v << " ";
        std::cout << std::endl;
        std::cout << "actual: ";
        for (auto& v : actual)
            std::cout << v << " ";
        std::cout << std::endl;
    }
}

//////////////// bubble sort n*n

template<typename T>
std::vector<T> bubble(const std::vector<T>& in)
{
    return in; 
}

int main()
{
    AreEqual<int>({}, bubble<int>({}));
    AreEqual<int>({1,1,3}, bubble<int>({1,3,1}));
    AreEqual<int>({1,2,3}, bubble<int>({3,2,1}));
    AreEqual<int>({1,2,3}, bubble<int>({1,2,3}));
    AreEqual<int>({1}, bubble<int>({1}));
    AreEqual<int>({9,9,9,9,9,9,9}, bubble<int>({9,9,9,9,9,9,9}));
    AreEqual<int>({1,1,3,5,9,11,23}, bubble<int>({5,3,9,11,23,1,1}));
}
