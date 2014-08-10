#include "test.hpp"

#include <string>
#include <sstream>

std::string itobr(int i)
{
    std::string s;
    for (int n = i, r = i % 2; n > 0; n = n >> 1, r = n % 2)
    {
        std::stringstream ss;
        ss << r << s;
        s = ss.str();
    }
    return std::move(s);
}

std::string br(const std::string& decimal)
{
    int i = std::stoi(decimal.substr(0, decimal.find('.')));
    int d = std::stoi(decimal.substr(decimal.find('.') + 1, std::string::npos));
    std::cout << "d: " << (decimal.find('.') == std::string::npos) << std::endl;

    return itobr(i) + "." + itobr(d);
}

int main()
{
    std::cout << 1 << " = " << br("1") << std::endl;
    std::cout << 2 << " = " << br("2") << std::endl;
    std::cout << 3 << " = " << br("3") << std::endl;
    std::cout << 4 << " = " << br("4") << std::endl;
    std::cout << 17 << " = " << br("17") << std::endl;
    std::cout << 19 << " = " << br("19") << std::endl;

    return 0;
}
