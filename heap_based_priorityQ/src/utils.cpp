#include <iostream>
#include <string>
#include <sstream>

#include "utils.hpp"

namespace utils {

void print(size_t index, const std::string& contents)
{
    std::cout << "\033[36m" << index << "\033[0m : "
              << contents << std::endl;
}

void print(const std::map<size_t, PriorityQueue>& queues)
{
    if (queues.empty())
    {
        std::cout << "<queue list empty>" << std::endl;
        return;
    }

    for (auto pair : queues)
    {
        print(pair.first, pair.second.toString());
    }
}

options str2enum(const std::string& command)
{
    if (command == "mk")
        return options::MK;
    if (command == "ls")
        return options::LS;
    if (command == "heapify")
        return options::HEAPIFY;
    if (command == "peek")
        return options::PEEK;
    if (command == "delete_root")
        return options::DELETE_ROOT;
    if (command == "update_key")
        return options::UPDATE_KEY;
    if (command == "add")
        return options::INSERT;
    if (command == "q")
        return options::Q;

    return options::UNKNOWN;
}

void read_input(std::istream& stream, std::string& command, std::vector<size_t>& arguments)
{
    std::cout << "Please insert instruction: ";

    std::string line;
    std::getline(stream, line);
    std::istringstream iss(line);

    iss >> command;

    std::string word;
    while (std::getline(iss, word, ' '))
        if (word.find('-') != 0 and (atoi(word.c_str()) != 0 or (atoi(word.c_str()) == 0 and word == "0")))
            arguments.push_back(atoi(word.c_str()));
}


} // end namespace utils
