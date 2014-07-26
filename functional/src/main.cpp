#include <iostream>
#include <vector>
#include <functional>


void take(int n, std::vector<int>(*f)(int))
{

}

int main()
{
    take(25, [](int n) -> std::vector<int> {
        std::vector<int> v;
        std::cout << n;
        for (int i = 0; i < n; i++)
            v.push_back(i);
        return std::move(v);
    });
    
    return 0;
}
