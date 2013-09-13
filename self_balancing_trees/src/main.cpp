#include <iostream>
#include <cstdio>
#include <string>
#include <vector>

#include "utils.hpp"
#include "avl.hpp"

AVL<std::string> g_avl;

int main()
{
    while (true)
    {
        ///////////// Read user input ////////////

        std::string command, value;
        size_t key;

        utils::read_input<size_t, std::string>(std::cin, command, key, value);

        ///////////// Process ///////////

        switch (utils::str2enum(command))
        {
            case options::LS:
            {
                g_avl.Print();
                break;
            }

            case options::ADD:
            {
                g_avl.insert(key, value);
                break;
            }

            case options::RM:
            {
                g_avl.remove(key);
                break;
            }

            case options::GET:
            {
                try
                {
                    std::cout << key << " = " << g_avl.lookup(key) << std::endl;
                }
                catch (const std::string& e)
                {
                    std::cout << "error: " << e << std::endl;
                }

                break;
            }

            case options::Q: { exit(0); break; }
            
            case options::UNKNOWN: { break; }
        }
    }

    return 0;
}
