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

//////////////// quicksort n*log n



int main()
{
    AreEqual<int>({1,1,3}, quicksort<int>({1,3,1}));
    AreEqual<int>({1,2,3}, quicksort<int>({3,2,1}));
    AreEqual<int>({1,2,3}, quicksort<int>({1,2,3}));
    AreEqual<int>({1}, quicksort<int>({1}));
    AreEqual<int>({9,9,9,9,9,9,9}, quicksort<int>({9,9,9,9,9,9,9}));
    AreEqual<int>({1,1,3,5,9,11,23}, quicksort<int>({5,3,9,11,23,1,1}));
    AreEqual<int>({}, quicksort<int>({}));
}
