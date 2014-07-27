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

struct D
{
    size_t column_axis;
    size_t row_axis;
};

template<typename T>
std::vector<T> zero(const std::vector<T>& in, const D& m, const D& e)
{
    std::vector<T> out = in;

    // zero column
    for (size_t i = 0; i < m.row_axis; i++)
        out.at(m.column_axis*i + e.column_axis) = 0;
    // zero row
    for (size_t i = 0; i < m.column_axis; i++)
        out.at(e.row_axis * m.column_axis + i) = 0;
    
    return std::move(out);
}

int main()
{
    AreEqual<int>({}, zero<int>({}, {0,0}, {0,0}));
    AreEqual<int>({1,0,1,0,0,0}, zero<int>({1,3,1,2,2,2}, {3,2}, {1,1}));
    AreEqual<int>({1,0,3,4,5,0,0,0,0,0,11,0,13,14,15},
                  zero<int>({1,2,3,4,5,6,7,8,9,10,11,12,13,14,15}, {5,3}, {1,1}));

    AreEqual<int>({0,0,0,0,0}, zero<int>({1,2,3,4,5}, {5,1}, {2,0}));
    AreEqual<int>({0,0,0,0,0}, zero<int>({1,2,3,4,5}, {1,5}, {0,1}));

    return 0;
}
