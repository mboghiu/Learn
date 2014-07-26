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

//////////////// mergesort n*log n

template<typename T>
std::vector<T> mergesort(const std::vector<T>& in);

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

    int x = 0;
    int y = 0;
    while (x < n && y < m)
    {
        if (lhs_sorted[x] <= rhs_sorted[y])
        {
            v.push_back(lhs_sorted[x]);
            x++;
        }
        else
        {
            v.push_back(rhs_sorted[y]);
            y++;
        }
    }

    if (x == n)
        for (int i = y; i < m; i++)
            v.push_back(rhs_sorted[i]);
    else if (y == m)
        for (int i = x; i < n; i++)
            v.push_back(lhs_sorted[i]);

    return std::move(v);
}

template<typename T>
std::vector<T> mergesort(const std::vector<T>& in)
{
    if (in.size() <= 1)
        return in;

    assert(in.size() > 1);

    return std::move(merge(
        std::vector<T>(in.begin(), in.begin() + in.size() / 2),
        std::vector<T>(in.begin() + in.size() / 2, in.end())
    ));
}

int main()
{
    AreEqual<int>({1,1,3}, mergesort<int>({1,3,1}));
    AreEqual<int>({1,2,3}, mergesort<int>({3,2,1}));
    AreEqual<int>({1,2,3}, mergesort<int>({1,2,3}));
    AreEqual<int>({1}, mergesort<int>({1}));
    AreEqual<int>({9,9,9,9,9,9,9}, mergesort<int>({9,9,9,9,9,9,9}));
    AreEqual<int>({1,1,3,5,9,11,23}, mergesort<int>({5,3,9,11,23,1,1}));
    AreEqual<int>({}, mergesort<int>({}));
}
