#include "utils.hpp"

namespace utils {

options str2enum(const std::string& command)
{
    if (command == "ls")
        return options::LS;
    if (command == "add")
        return options::ADD;
    if (command == "rm")
        return options::RM;
    if (command == "get")
        return options::GET;
    if (command == "set")
        return options::SET;

    if (command == "q")
        return options::Q;

    return options::UNKNOWN;
}

} // end namespace utils
