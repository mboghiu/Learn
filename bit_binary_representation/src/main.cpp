#include "test.hpp"

#include <string>


std::string itobr(int i)
{
    for (int cat = i, rest = i%2; cat != 0; cat = cat / 2, rest = cat % 2)
        std::cout << "r: " << rest << std::endl;

    return "";
}

std::string br(const std::string& decimal)
{
    int r = std::stoi(decimal);

    return itobr(r);
}

int main()
{

    return 0;
}
