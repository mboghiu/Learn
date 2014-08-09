#include "graph.hpp"

#include <utility>

void graph::add(const node& n)
{
    _graph[n] = std::set<node>();
}

void graph::add(const edge& e)
{
    _graph[e.from].insert(e.to);
}
