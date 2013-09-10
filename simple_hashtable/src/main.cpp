#include <iostream>
#include <cstdio>
#include <string>
#include <vector>

#include "utils.hpp"
#include "hashtable.hpp"

const size_t g_size = 10;

HashTable<const std::string, std::string> g_table(g_size, [] (const std::string& key) -> int
{
    std::hash<std::string> m_hash;

    size_t index = m_hash(key);

    std::cout << "\033[37mhash(" << key << ") = " << (index % g_size) << "\033[0m" << std::endl;

    return static_cast<int>(index % g_size);
});

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
                g_table.print();
                break;
            }

            case options::ADD:
            {
                g_table.add(key, value); 
                break;
            }

            case options::RM:
            {
            }

            case options::GET:
            {
            }

            case options::SET:
            {
            }

            /* exits */
            case options::Q:
                exit(0);
            case options::UNKNOWN:
                break;
        }
    }

    return 0;
}
