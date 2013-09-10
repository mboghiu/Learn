#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

enum class options {LS, ADD, RM, GET, SET, Q, UNKNOWN};

namespace utils
{
    options str2enum(const std::string& command);

    template<typename Key, typename Value>
    void read_input(std::istream& stream, std::string& command, Key& key, Value& value);
}

///////////// definitions /////////////

template<typename Key, typename Value>
void utils::read_input(std::istream& stream, std::string& command, Key& key, Value& value)
{
    std::cout << ">> ";

    std::string input;
    std::getline(stream, input);
    std::istringstream iss(input);

    iss >> command;
    iss >> key;
    iss >> value;
}
