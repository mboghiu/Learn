#include <algorithm>
#include <vector>
#include <iostream>

void read(std::vector<int>& v, size_t n)
{
    v.resize(n);
    for (auto& x : v)
        std::cin >> x;
}

void write(const std::vector<int>& v)
{
    for (const auto& x : v)
        std::cout << x << "|";
    std::cout << std::endl;
}

void doubleAll(std::vector<int>& v)
{
    for (auto& x : v)
        x *= 2;
}

int main()
{
    std::vector<int> v;
    read(v, 5);
    
    std::transform(v.begin(), v.end(), v.begin(), [](int i) -> int { return i*2; });

    write(v);
    return 0;
}
