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

template<typename T>
size_t partition(std::vector<T>& v, size_t pivot_index)
{
    T pivot = v[pivot_index];

    // move pivot to the right-most position
    std::swap(v[v.size() - 1], v[pivot_index]);

    size_t cutoff_index = 0;
    for (size_t i = 0; i < v.size() - 1; i++)
        if (v[i] <= pivot)
        {
            std::swap(v[i], v[cutoff_index]);
            cutoff_index++;
        }
    std::swap(v[v.size() - 1], v[cutoff_index]);

    return cutoff_index;
}

template<typename T>
std::vector<T> quicksort(const std::vector<T>& in) /* not in place for inlined unit tests */
{
    if (in.size() <= 1)
        return in;

    T pivot = in[0];
    
    std::vector<T> v = in;
    size_t pivot_final_position = partition<T>(v, 0); /* in place */

    auto v1 = quicksort(std::vector<T>(v.begin(), v.begin() + pivot_final_position));
    auto v2 = quicksort(std::vector<T>(v.begin() + pivot_final_position + 1, v.end()));

    v1.push_back(pivot);
    v1.insert(v1.end(), v2.begin(), v2.end());
    return v1; 
}

int main()
{
    AreEqual<int>({}, quicksort<int>({}));
    AreEqual<int>({1,1,3}, quicksort<int>({1,3,1}));
    AreEqual<int>({1,2,3}, quicksort<int>({3,2,1}));
    AreEqual<int>({1,2,3}, quicksort<int>({1,2,3}));
    AreEqual<int>({1}, quicksort<int>({1}));
    AreEqual<int>({9,9,9,9,9,9,9}, quicksort<int>({9,9,9,9,9,9,9}));
    AreEqual<int>({1,1,3,5,9,11,23}, quicksort<int>({5,3,9,11,23,1,1}));
}
