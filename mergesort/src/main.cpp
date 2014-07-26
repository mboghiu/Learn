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

template<typename T>
std::vector<T> merge(const std::vector<T>& lhs, const std::vector<T> rhs)
{
    size_t n = lhs.size();
    size_t m = rhs.size();

    std::vector<T> v;

    if (n == 1 && m == 1)
    {
        v.push_back(std::min(lhs[0], rhs[0]));    
        v.push_back(std::max(lhs[0], rhs[0]));    
        return std::move(v);
    }

    std::vector<T> lhs_sorted = mergesort(lhs);
    std::vector<T> rhs_sorted = mergesort(rhs);

    for (size_t x = 0; x < std::min(n, m), x++)
    {
        v.push_back(
    }

}

template<typename T>
std::vector<T> mergesort(const std::vector<T>& in)
{
    if (in.size() == 1)
        return in;

    return std::move(merge(
        std::vector<T>(v.begin(), v.begin() + v.size() / 2),
        std::vector<T>(v.begin() + v.size() / 2 + 1, v.end())
    ));
}

int main()
{
    AreEqual<int>({1,1,3}, mergesort<int>({1,3,1}));
    AreEqual<int>({1,2,3}, mergesort<int>({3,2,1}));
    AreEqual<int>({1,2,3}, mergesort<int>({1,2,3}));
    AreEqual<int>({}, mergesort<int>({}));
}
