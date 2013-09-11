#include "utils.hpp"

namespace utils {

options str2enum(const std::string& command)
{
    if (command == "ls")
        return options::LS;

    if (command == "q")
        return options::Q;

    return options::UNKNOWN;
}

} // end namespace utils
