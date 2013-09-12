#include <iostream>
#include <cstdio>
#include <string>
#include <vector>

#include "utils.hpp"
#include "df.hpp"
#include "matrix_graph.hpp"

MatrixGraph<std::string> g_matrixRep(8);

int main()
{
    while (true)
    {
        ///////////// Read user input ////////////

        std::string command;
        size_t x, y;

        utils::read_input<size_t, size_t>(std::cin, command, x, y);

        ///////////// Process ///////////

        switch (utils::str2enum(command))
        {
            case options::LS:
            {
                g_matrixRep.Print();
                break;
            }

            case options::ADD:
            {
                g_matrixRep.AddEdge(x, y);
                break;
            }

            case options::ADDB:
            {
                g_matrixRep.AddEdge(x, y);
                g_matrixRep.AddEdge(y, x);
                break;
            }

            case options::RM:
            {
                g_matrixRep.RemoveEdge(x, y);
                break;
            }

            case options::ADJ:
            {
                std::cout << (g_matrixRep.AreAdjacent(x, y) ? "yes" : "no") << std::endl;
                break;
            }

            case options::LSN:
            {
                for (auto neighbour : g_matrixRep.GetNeighbours(x))
                    std::cout << neighbour << " ";
                std::cout << std::endl;
                break;
            }

            case options::DF:
            {
                traversal::df(g_matrixRep);
                break;
            }

            case options::BF:
            {
                break;
            }

            case options::Q: { exit(0); break; }
            
            case options::UNKNOWN: { break; }
        }
    }

    return 0;
}
