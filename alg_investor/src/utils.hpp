#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

enum class options {LS, Q, UNKNOWN};

namespace utils
{
    options str2enum(const std::string& command);

    template<typename Offer>
    void read_input(std::istream& stream, double& capital, int& n, std::vector<Offer>& values);
}

///////////// definitions /////////////

template<typename Offer>
void utils::read_input(std::istream& stream, double& capital, int& n, std::vector<Offer>& values)
{
    std::cout << ">> ";

    std::string input;
    std::getline(stream, input);
    std::istringstream iss(input);

    iss >> capital;
    iss >> n;

    for (int x = 0; x < n; x++)
    {
        double invest;
        double profit;
        iss >> invest;
        iss >> profit;
        values.push_back(Offer(invest,profit));
    }
}
