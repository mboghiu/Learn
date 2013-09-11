#include <iostream>
#include <cstdio>
#include <string>
#include <vector>

#include "utils.hpp"
#include "MatrixGraph.hpp"

MatrixGraph<std::string> g_matrixRep(8);

int main()
{
    while (true)
    {
        ///////////// Read user input ////////////

        std::string command, key, value;

        utils::read_input<std::string, std::string>(std::cin, command, key, value);

        ///////////// Process ///////////

        switch (utils::str2enum(command))
        {
            case options::LS:
            {
                g_matrixRep.Print();
                break;
            }

            case options::Q: { exit(0); break; }
            
            case options::UNKNOWN: { break; }
        }
    }

    return 0;
}
