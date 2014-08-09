#include "graph.hpp"

#include <utility>
#include <iostream>

void graph::add(const node& n)
{
    _graph[n] = std::set<node>();
}

void graph::add(const edge& e)
{
    _graph[e.from].insert(e.to);
}

void graph::peek() const
{
    for (auto pair : _graph)
    {
        std::cout << pair.first.key << "--> ";
        for (auto node : pair.second)
            std::cout << node.key << " ";
        std::cout << std::endl;
    }
}
