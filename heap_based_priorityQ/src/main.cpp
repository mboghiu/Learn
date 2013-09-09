#include <string>
#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
#include <sstream>

#include "priority_queue.hpp"
#include "utils.hpp"

std::map<size_t, PriorityQueue> g_queues;

size_t g_current_index = 0;

int main()
{
    while (true)
    {
        std::string command;
        std::vector<size_t> arguments;
        utils::read_input(std::cin, command, arguments);

        switch (utils::str2enum(command))
        {
            case options::MK:
            {
                g_queues.insert(std::make_pair(++g_current_index, PriorityQueue()));
                break;
            }

            case options::LS:
            {
                if (arguments.size() == 0)
                    utils::print(g_queues); 
                else if (g_queues.find(arguments.at(0)) != g_queues.end())
                    utils::print(arguments.at(0), g_queues.at(arguments.at(0)).toString());
                break;
            }

            case options::HEAPIFY:
            {
                if (arguments.size() == 0)
                    std::cout << "Sorry you need to give a list of numbers to heapify." << std::endl;
                else
                    g_queues.insert(std::make_pair(++g_current_index, PriorityQueue(arguments)));
                break;
            }

            case options::PEEK:
            {
                if (arguments.size() == 0)
                    for ( auto q : g_queues )
                        std::cout << "\033[36m" << q.first << "\033[0m: " << q.second.peek() << std::endl;
                else
                    for ( auto q : arguments )
                        if (g_queues.find(arguments.at(q)) != g_queues.end())
                            std::cout << "\033[36m" << q << "\033[0m: " << g_queues.at(arguments.at(q)).peek() << std::endl;
                    
                break;
            }

            case options::DELETE_ROOT:
            {
                if (arguments.size() == 0)
                    for ( auto q : g_queues )
                        q.second.pop();
                else
                    for ( auto q : arguments )
                        if (g_queues.find(arguments.at(q)) != g_queues.end())
                            g_queues.at(arguments.at(q)).pop();
                    
                break;
            }

            case options::UPDATE_KEY:
            {
                std::cout << " UPDATE_KEY.." << std::endl;
                break;
            }

            case options::INSERT:
            {
                if (arguments.size() == 0)
                    std::cout << "Sorry, you need to provide an element to insert." << std::endl;
                else if (arguments.size() == 1)
                {
                    if (g_queues.size() == 1)
                        g_queues.at(1).insert(arguments.at(0));
                    else
                        std::cout << "You want to insert an element in queue " << arguments.at(0) << " but did not specify which." << std::endl;
                }
                else if (arguments.size() == 2 and g_queues.find(arguments.at(0)) != g_queues.end())
                        g_queues.at(arguments.at(0)).insert(arguments.at(1));
                else if (g_queues.find(arguments.at(0)) != g_queues.end())
                        g_queues.at(arguments.at(0)).insert(arguments);
                    
                break;
            }

            case options::Q:
            {
                exit(0);
            }

            case options::UNKNOWN:
            {
                std::cout << "Unknown instruction \033[31m" << command
                          << "\033[0m, please try again:" << std::endl;
                break;
            }
        }
    }

    return 0;
}
