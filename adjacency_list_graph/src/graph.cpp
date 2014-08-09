#include "graph.hpp"

#include <utility>

void graph::add(const node& n)
{
    _graph[n] = std::set<node>();
}
